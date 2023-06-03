#include "playground.h"

#include <mutex>

#include <SDL.h>

#include "fml/closure.h"
#include "fml/logging.h"

namespace tcr {

Playground::Playground() = default;

Playground::~Playground() = default;

bool Playground::OpenPlaygroundHere(PlaygroundCallback callback) {
  if (!callback) {
    return false;
  }

  if (::SDL_Init(SDL_INIT_VIDEO) != 0) {
    return false;
  }
  fml::ScopedCleanupClosure sdl_quit([]() { ::SDL_Quit(); });

  Uint32 window_flags = SDL_WINDOW_RESIZABLE;
  SDL_Window* window = nullptr;
  SDL_Renderer* renderer = nullptr;

  if (::SDL_CreateWindowAndRenderer(1080,          //
                                    720,           //
                                    window_flags,  //
                                    &window,       //
                                    &renderer      //
                                    ) != 0) {
    return false;
  }

  fml::ScopedCleanupClosure destroy_window_and_renderer([window, renderer]() {
    ::SDL_DestroyRenderer(renderer);
    ::SDL_DestroyWindow(window);
  });

  Texture texture;
  SDL_Event event = {};
  bool is_running = true;
  while (is_running) {
    // Process all events.
    while (::SDL_PollEvent(&event) != 0) {
      switch (event.type) {
        case SDL_EVENT_KEY_UP:
          switch (event.key.keysym.sym) {
            case SDL_KeyCode::SDLK_q:
            case SDL_KeyCode::SDLK_ESCAPE:
              is_running = false;
              break;
            default:
              break;
          }
          break;
        case SDL_EVENT_QUIT:
          is_running = false;
          break;
        default:
          break;
      }
    }
    // Resize surface to match window size.
    int width = 0;
    int height = 0;
    if (SDL_GetWindowSizeInPixels(window, &width, &height) != 0) {
      return false;
    }
    if (!texture.Resize({width, height})) {
      return false;
    }
    // Invoke the callback.
    if (!callback(texture)) {
      return false;
    }
    // Present the surface.
    SDL_Surface* surface =
        ::SDL_CreateSurfaceFrom(texture.At(0, 0),           // pixels
                                texture.GetSize().x,        // width
                                texture.GetSize().y,        // height
                                texture.GetPitchInBytes(),  // pitch in bytes
                                SDL_PIXELFORMAT_ARGB8888    // format
        );
    if (!surface) {
      return false;
    }
    fml::ScopedCleanupClosure cleanup_surface(
        [surface]() { ::SDL_DestroySurface(surface); });

    SDL_Texture* texture = ::SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
      return false;
    }
    fml::ScopedCleanupClosure cleanup_texture(
        [texture]() { ::SDL_DestroyTexture(texture); });

    if (::SDL_RenderTexture(renderer, texture, nullptr, nullptr) != 0) {
      return false;
    }
    if (::SDL_RenderPresent(renderer) != 0) {
      return false;
    }
  }
  return true;
}

}  // namespace tcr
