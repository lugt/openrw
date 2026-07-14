# Opcode 文件拆分 Spec

> **状态:已完成 (2026-07-14)** — `GTA3ModuleImpl.inl`(原 12894 行)已删除,904 个 opcode 迁入 10 个域文件。提交链:4fd0de4e(阶段0 ControlFlow) → b1a555d5(剩余 9 域)。编译链接通过,`--newgame` 运行冒烟无 `IllegalInstruction`。

## 一、背景与动机

`rwengine/src/script/modules/GTA3ModuleImpl.inl` 当前 **12894 行 / 326KB**,包含全部 904 个 SCM opcode 实现函数。对 AI Agent 工作流带来:

- **上下文窗口超载**:单文件超 13K 行,远超单次高效处理范围,每次读写都消耗大量 token
- **注意力分散**:任务/车辆/角色/文本等无关 opcode 混在一起,定位特定功能需全文扫描
- **协作冲突**:多人/多 agent 同时改不同功能域会频繁冲突

**目标**:按功能域拆分为多个内聚的小 `.inl` 文件,每个聚焦单一子系统,便于 AI 和人工定位修改。配合 [[OPCODE_STATUS]] 的功能域分类作为 opcode 归属依据。

## 二、可行性验证(关键技术结论)

经代码分析确认,拆分是机械操作、低风险:

1. **`.inl` 全是独立的顶层 opcode 函数**:904 个函数全是 `void/bool opcode_NNNN(...)` 全局函数,**无命名空间、无 static helper、无全局变量、无共享辅助函数**。每个 opcode 自包含,可整块剪切迁移。
2. **函数定义顺序无关**:opcode 通过 `GTA3Module.cpp` 构造函数里的 `bind(id, argc, fn)` 注册,与 `.inl` 内函数定义顺序无关。重新排列/分散不影响注册。
3. **`#include` 机制标准**:`.inl` 由 `GTA3Module.cpp:14` 用 `#include` 引入。拆分后改为 include 多个 `.inl`,机制不变。
4. **依赖集中**:`.inl` 顶部有 20 个 `#include`(GameWorld/各 Object/ScriptTypes 等),是全部 opcode 的依赖并集。`RW_UNIMPLEMENTED_OPCODE` 宏在 `GTA3Module.cpp:7-12` 定义,位于 include `.inl` 之前。

## 三、文件划分方案

按功能域划分为 **10 个文件**,合并过小域、保持大域独立(配合 [[OPCODE_STATUS]] 分类):

| 新文件 | 源功能域 | opcode 数 | 预估行数 |
|---|---|---|---|
| `ControlFlow.inl` | 流程控制与线程 + 系统与平台 | 54 | ~760 |
| `Variables.inl` | 变量与数学运算 | 205 | ~2870 |
| `Objects.inl` | 物件操作与碰撞 + 特效 | 134 | ~1880 |
| `Characters.inl` | 角色与 AI 行为 | 187 | ~2620 |
| `Vehicles.inl` | 车辆 | 79 | ~1110 |
| `Camera.inl` | 摄像机 + 过场动画 | 35 | ~490 |
| `Mission.inl` | 任务与脚本事件 + 拾取物与武器 | 80 | ~1120 |
| `TextUI.inl` | 文本与 UI | 56 | ~790 |
| `World.inl` | 环境天气时间 + 区域与车库 + 地图标记 | 26 | ~370 |
| `Misc.inl` | 音频 + 输入控制 + 统计与存档 + 未归类 | 48 | ~670 |
| **合计** | | **904** | **~12870** |

> 设计权衡:`Variables.inl`(205)和 `Characters.inl`(187)仍较大,但功能内聚、各自聚焦单一域,已远优于 13K 行混合文件。后续若仍嫌大,可二次拆分(如 `Variables.inl` 拆为赋值/算术 + 数学比较)。**不建议一次拆到 18 个文件**--过碎会增加 include 管理成本且收益递减。

## 四、依赖处理方案

**采用"集中 include"策略**--子 `.inl` 保持纯函数、零 include,最利于 AI 阅读:

```
GTA3Module.cpp 结构(修改后):
  #include "script/modules/GTA3Module.hpp"
  #include "script/ScriptModule.hpp"
  #include "script/ScriptTypes.hpp"

  // RW_UNIMPLEMENTED_OPCODE 宏定义(原位置不动,7-12行)

  // ---- 从原 .inl 顶部迁移来的 20 个游戏逻辑头(全部 opcode 依赖并集)----
  #include <ai/PlayerController.hpp>
  #include <audio/SfxParameters.hpp>
  #include <core/Logger.hpp>
  #include <data/CutsceneData.hpp>
  #include <engine/Animator.hpp>
  #include <engine/GameData.hpp>
  #include <engine/GameState.hpp>
  #include <engine/GameWorld.hpp>
  #include <engine/Payphone.hpp>
  #include <objects/CharacterObject.hpp>
  #include <objects/CutsceneObject.hpp>
  #include <objects/InstanceObject.hpp>
  #include <objects/ObjectTypes.hpp>
  #include <objects/PickupObject.hpp>
  #include <objects/VehicleObject.hpp>
  #include <script/SCMFile.hpp>
  #include <script/ScriptFunctions.hpp>
  #include <script/ScriptMachine.hpp>
  #include <script/ScriptTypes.hpp>
  #include <boost/algorithm/string/predicate.hpp>

  // ---- 各功能域实现 ----
  #include "ControlFlow.inl"
  #include "Variables.inl"
  #include "Objects.inl"
  #include "Characters.inl"
  #include "Vehicles.inl"
  #include "Camera.inl"
  #include "Mission.inl"
  #include "TextUI.inl"
  #include "World.inl"
  #include "Misc.inl"
```

子 `.inl` 文件**不含任何 include**,只含 opcode 函数 + 其 Doxygen 注释。

> 备选:若担心 `.cpp` 变臃肿,可把 20 个 include 提取到新文件 `GTA3ModuleImplDeps.hpp`,由 `.cpp` 和(如需)子 `.inl` include。当前方案优先简单,20 个 include 留 `.cpp` 即可。

## 五、实施步骤(分阶段,每阶段可独立验证)

每个 opcode 的归属依据 [[OPCODE_STATUS]] 各域明细(已按域列出全部 opcode ID)。迁移时按该文档把对应 `opcode_NNNN` 函数(含 Doxygen 块)剪切到目标文件。

### 阶段 0:试点验证机制(单域)
1. 创建 `rwengine/src/script/modules/ControlFlow.inl`(空)
2. 把原 `.inl` 顶部 20 个 `#include` 迁到 `GTA3Module.cpp`(宏定义之后)
3. 把"流程控制与线程"域的 54 个 opcode 函数从 `.inl` 剪切到 `ControlFlow.inl`
4. `GTA3Module.cpp` 增加 `#include "ControlFlow.inl"`,移除 `#include "GTA3ModuleImpl.inl"`(或暂时保留其余)
5. **编译验证 + 运行验证**(`--newgame` 确认游戏正常)

> 试点先做单域,确认 #include 顺序、宏可见性、依赖完整无误,再推广。

### 阶段 1-N:逐域迁移
对剩余 9 个域,每次迁移一个文件,步骤同上:
- 创建 `XxxYyy.inl` -> 剪切对应域 opcode -> `.cpp` 加 include -> 编译运行验证 -> 提交

每步独立提交,出问题易二分定位。

### 阶段末:清理
- 删除空的 `GTA3ModuleImpl.inl`(或保留为聚合入口)
- 确认 `GTA3Module.cpp` 的 include 列表干净
- 更新 `.clang-format` / iwyu 配置(如有)

## 六、验证方法

每阶段迁移后:

1. **编译**:`cmake --build build -j`,0 error
2. **opcode 计数对齐**:`grep -c "RW_UNIMPLEMENTED_OPCODE\|void opcode_\|bool opcode_" 各 .inl | 求和` = 904
3. **运行冒烟**:`./build/rwgame/rwgame --gamedata <GTAIII路径> --newgame` 能正常进入游戏渲染(参考音频修复时的验证:`Sound source finished loading` 持续增长、CPU 进入渲染开销而非死循环)
4. **opcode 注册无遗漏**:`--newgame` 不报 `IllegalInstruction`(未知 opcode 会抛此异常)

## 七、风险与回滚

| 风险 | 缓解 |
|---|---|
| 漏迁移某 opcode 导致 `IllegalInstruction` | 验证步骤 4 运行冒烟;阶段 0 试点先行 |
| 头文件依赖缺失(某子域需要未列出的头) | 20 个 include 是原 `.inl` 依赖并集,已覆盖;若编译报缺头,补到 `.cpp` |
| `#include` 顺序导致宏不可见 | 宏定义必须在所有 `.inl` include 之前(方案已保证) |
| 剪切粘贴出错(漏/重) | 编译会捕获重复定义;漏迁移由运行冒烟捕获 |

**回滚**:每阶段独立 git 提交,出问题 `git revert` 单个提交即可,不影响其他域。

## 八、与音频修复解耦

本拆分是纯文件重组,不改任何 opcode 逻辑,与已完成 的 [[../openrw-project]] SFX 音频修复(FFmpeg `read_packet` EOF)完全解耦。可独立进行、独立提交。
