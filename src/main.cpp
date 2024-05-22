#include <SDL2/SDL.h>
#include <spdlog/spdlog.h>

static constexpr int NTSC_WIDTH = 256;
static constexpr int NTSC_HEIGHT = 224;

static SDL_Window *window;

static void cleanup() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main() {
    atexit(cleanup);

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        spdlog::error("Failed to initialize SDL2: {}", SDL_GetError());
        return EXIT_FAILURE;
    }

    window = SDL_CreateWindow("NES Emulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, NTSC_WIDTH, NTSC_HEIGHT, 0);
    if (window == nullptr) {
        spdlog::error("Failed to create window: {}", SDL_GetError());
        return EXIT_FAILURE;
    }

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;
        }
    }

    return EXIT_SUCCESS;
}