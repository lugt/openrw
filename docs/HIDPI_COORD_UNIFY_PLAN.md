# 统一 2D 坐标空间:窗口/DPI/输入/HUD/ImGui 系统化方案

## 背景与根因

`78ede50c` 启用 `SDL_WINDOW_ALLOW_HIGHDPI` 后,2D 坐标系统被劈成三个互不一致的空间:

| 空间 | 来源 | 数值(Retina 2x) | 谁在用 |
|---|---|---|---|
| **物理** | `getSize()`=`SDL_GL_GetDrawableSize` | 2560x1440 | `glViewport`、`projection2D`、HUD 位置算法、3D aspect、`glm::project` |
| **逻辑** | SDL 鼠标事件 `x/y`、`SDL_GetWindowSize`、ImGui 内部 | 1280x720 | `Menu::click/hover`、ImGui |
| **设计常量** | 硬编码 | 200/30/50、640x480 | Menu offset、`hudParameters`、opcode text_draw |

`9d060ac9` 的 `dpiScale`(只把 HUD 设计参数 x 物理/480)只补了 HUD 一个口子,菜单/鼠标/Loading 文字/ImGui 的 `glm::project` 都没碰。`setProjection2DSize` 是零调用的死代码。

核心问题:**2D 投影用物理像素,但鼠标/菜单用逻辑像素,二者差 DPI 倍。** 拖拽窗口、不同分辨率、HiDPI 缩放都会改变逻辑窗口尺寸,所以方案必须动态响应。

## 已定方向(用户确认)

**基准:逻辑窗口空间 + 设计缩放(方案A)**

- 投影 = 逻辑窗口尺寸(随窗口拖拽/分辨率/DPI 动态变)
- `designScale = 逻辑宽 / 640`(640x480 仅作基准常量)
- 鼠标天然与 UI 同空间对齐
- `glViewport` 仍覆盖物理 framebuffer(Retina 清晰度由 `ALLOW_HIGHDPI` 保证)
- 任意窗口尺寸 UI 等比缩放,Resize 下一帧自动生效(无需事件处理,因 `setViewport` 每帧调用)

## 设计核心:统一坐标层

引入一个明确的坐标约定,所有 2D 元素在**逻辑窗口空间**定义,投影也映射到逻辑窗口空间。物理 framebuffer 仅 `glViewport` 用,不进 2D 投影。

```
设计像素(640x480 基准常量) --xdesignScale--> 逻辑窗口空间(投影)
                                                ^
                                      鼠标事件(SDL,天然逻辑)
                                                ^
                                      ImGui(内部逻辑,DisplayFramebufferScale 自洽)
```

`designScale` 取代当前的 `dpiScale`:从"设计->物理"改为"设计->逻辑"。

## 改动清单

### 1. GameWindow:暴露逻辑尺寸(`rwgame/GameWindow.hpp/.cpp`)
- 新增 `glm::ivec2 getLogicalSize() const`,调用 `SDL_GetWindowSize`(逻辑像素)
- 保留 `getSize()`=`SDL_GL_GetDrawableSize`(物理,供 `glViewport`)
- 注释说明二者区别与各自用途

### 2-3. 投影与 viewport 解耦(`rwgame/RWGame.cpp:678-679` + `OpenGLRenderer` + `GameRenderer`)

**精确链路(已确认):**
- `GameRenderer::setViewport(物理 w,h)`(`GameRenderer.cpp:547`):设 `OpenGLRenderer::viewport`=物理 + 重建 FBO 纹理(`glTexImage2D` 用物理,`:554-562`)
- `GameRenderer::setupRender()`(`:172-178`):`glViewport(物理)`(从 `getViewport()` 读物理)
- `OpenGLRenderer::setViewport(物理)`(`OpenGLRenderer.cpp:99`):设 `projection2D=ortho(物理)` <- **唯一要改的点**

**结论:viewport(物理)和 FBO 必须保持物理;只有 `projection2D` 改用逻辑。** 不要动 `setViewport` 的物理语义(否则破坏 FBO/glViewport),而是把 `projection2D` 从 `setViewport` 解耦,单独用逻辑尺寸设置。

```cpp
// RWGame.cpp render():
glm::ivec2 physSize = getWindow().getSize();        // 物理:glViewport/FBO
glm::ivec2 logSize  = getWindow().getLogicalSize(); // 逻辑:投影+3D aspect
renderer.setViewport(physSize.x, physSize.y);       // 物理,不变(含FBO重建)
renderer.getRenderer().setProjection2D(logSize.x, logSize.y); // 逻辑投影
viewCam.frustum.aspectRatio = logSize.x / float(logSize.y); // 3D用逻辑
```

- `OpenGLRenderer::setViewport` 保持现状(viewport=物理 + `projection2D=ortho(物理)`,给 rwviewer 默认行为)
- **复活死代码** `setProjection2DSize` 改名为 `setProjection2D(refW, refH)`,游戏每帧调用传逻辑尺寸;rwviewer 不调,保持物理 ortho
- `get2DProjection()` 不变,TextRenderer(`:335`)/MapRenderer(`:91`)自动跟随新投影

**rwviewer 兼容:** `ViewerWidget.cpp:137/148` 用 Qt `devicePixelRatio` 全物理,不调 `setProjection2D`,保持 `setViewport` 默认的物理 ortho - 不受影响。

### 4. HUDDrawer:`dpiScale` -> `designScale`(`rwgame/HUDDrawer.hpp/.cpp`)
- `float designScale = 1.f;` 每帧 `= getLogicalSize().y / kScreenVirtualHeight`
- 所有 `*dpiScale` 改 `*designScale`(margin/size/offset)
- HUD 位置算法从 `getViewport().x`(物理)改 `getLogicalSize().x`(逻辑)
- opcode 文字归一化(`:293`):`position/640x480 * logicalVP`(从物理改逻辑)

### 5. 菜单系统:offset/size 应用 designScale(`rwgame/MenuSystem.cpp/.hpp` + `MenuState.cpp`)
- `Menu::draw/hover/click` 接收 designScale(或从 GameRenderer 取),对 `offset`/`size` 应用
- `MenuState.cpp:29` `glm::vec2(200.f,200.f)` 保持设计值,运行时 x designScale
- 鼠标坐标(`State.cpp:34/38`)保持逻辑(与投影同空间,天然对齐,无需转换)

### 6. LoadingState 文字(`rwgame/states/LoadingState.cpp:35-36`)
- `ti.size=25.f`、`screenPosition=(50.f, size.y - 25 - 50)` 改用逻辑 size + designScale

### 7. ImGui `glm::project` 修正(`rwgame/RWImGui.cpp:84-95`)
- `size = getLogicalSize()`(从物理改逻辑),`glm::project` viewport 用逻辑
- `SetNextWindowPos` 的坐标随之逻辑化(ImGui 内部逻辑,一致)

### 8. IngameState 鼠标视角归一化(`rwgame/states/IngameState.cpp:362`)
- `screenSize = getLogicalSize()`(从物理改逻辑),`xrel/screenSize` 归一化正确(逻辑增量/逻辑尺寸)
- 顺带修当前灵敏度被物理尺寸压低 2x 的隐 bug

### 9. 清理
- 删除 `RWGame.cpp` 临时截图代码(本次验证用)
- `setProjection2DSize` 复活为 `setProjection2D`(非删除)

## 关键正确性约束

1. **`glViewport` 必须物理**,否则 Retina 只渲染左下角四分之一
2. **`projection2D` 必须逻辑**,才能与逻辑鼠标/ImGui 对齐
3. **3D aspect** 用逻辑(视觉正确,与窗口显示一致)
4. **`designScale` 基准**统一用 `kScreenVirtualHeight`(480),非物理
5. **ImGui 不需动 DPI**(后端自洽),但 `glm::project` 的 viewport 要逻辑
6. **无需 Resize 事件处理**:`setViewport` 每帧调用,拖拽后自动跟随

## 跨平台一致性(回应 Wayland Agent)

- macOS:逻辑=1280,物理=2560,`ALLOW_HIGHDPI` 给物理清晰度,投影逻辑化给对齐
- Wayland 分数缩放:`SDL_GetWindowSize` 给逻辑(已含缩放),`SDL_GL_GetDrawableSize` 给物理,方案天然适配
- X11:同上,二者比例与 DPI 一致
- Ubuntu Agent 之前 pin 投影(ec861259)是为修 Wayland 字号过小 - 本方案用 designScale 缩放字号,Wayland 同样生效,且不破坏定位

## 验证

- [ ] macOS Retina:菜单鼠标命中对齐、HUD 位置正确、文字不模糊
- [ ] 拖拽窗口:UI 等比缩放,无错位
- [ ] 截图(glReadPixels->PPM->PNG)视觉确认
- [ ] 编译无 warning
- [ ] 邀请 Ubuntu Agent 在 Wayland 确认不回归

## 风险

- `designScale` 改基准后,HUD 视觉大小可能微变(从物理基准到逻辑基准),需视觉确认
- opcode text_draw 归一化改逻辑后,GTA III 脚本文字位置应不变(比例一致)
- `Menu::draw/hover/click` 引入 designScale 参数需改动签名,波及 `State.cpp` 调用点
