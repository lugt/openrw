#include "LoadingState.hpp"
#include "RWGame.hpp"

#include <engine/ScreenText.hpp>

LoadingState::LoadingState(RWGame* game, const std::function<void(void)>& callback)
    : State(game), complete(callback) {
}

void LoadingState::enter() {
    game->newGame();
}

void LoadingState::exit() {
}

void LoadingState::tick(float dt) {
    RW_UNUSED(dt);

    done();
    complete();
}

bool LoadingState::shouldWorldUpdate() {
    return false;
}

void LoadingState::handleEvent(const SDL_Event& e) {
    State::handleEvent(e);
}

void LoadingState::draw(GameRenderer& r) {
    // Display some manner of loading screen.
    const glm::ivec2 size = r.getLogicalSize();
    const float designScale = size.y / kScreenVirtualHeight;
    TextRenderer::TextInfo ti;
    ti.text = GameStringUtil::fromString("Loading...", FONT_ARIAL);
    ti.size = 25.f * designScale;
    ti.screenPosition = glm::vec2(50.f * designScale,
                                  static_cast<float>(size.y) - ti.size - 50.f * designScale);
    ti.font = FONT_ARIAL;
    ti.baseColour = glm::u8vec3(255);
    r.text.renderText(ti);
}
