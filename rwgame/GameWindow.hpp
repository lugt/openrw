#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

#include <SDL_surface.h>
#include <SDL_video.h>

#include <glm/vec2.hpp>
#include <string>
#include <tuple>
#include <SDL.h>

class GameWindow {
    SDL_Window* window = nullptr;
    SDL_Surface* icon = nullptr;
    SDL_GLContext glcontext{nullptr};
public:
    GameWindow() = default;

    void create(const std::string& title, size_t w, size_t h, bool fullscreen);
    void close();

    void showCursor();
    void hideCursor();

    /// Physical framebuffer size in pixels (SDL_GL_GetDrawableSize). Used for
    /// glViewport / FBO allocation. On HiDPI this is the logical size scaled by
    /// the display's DPI factor.
    glm::ivec2 getSize() const;

    /// Logical (window) size in points (SDL_GetWindowSize). Mouse events,
    /// ImGui, and the 2D orthographic projection operate in this space, so it
    /// is the reference for all 2D UI layout and hit-testing. On non-HiDPI
    /// displays this equals getSize().
    glm::ivec2 getLogicalSize() const;

    void swap() const {
        SDL_GL_SwapWindow(window);
    }

    bool isOpen() const {
        return !!window;
    }

    std::tuple<SDL_Window *, SDL_GLContext> getSDLContext() {
        return std::make_tuple(window, glcontext);
    }
};

#endif
