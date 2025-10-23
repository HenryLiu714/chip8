#include <display.h>

#include <iostream>
#include <SDL2/SDL.h>

Display::Display() {
    if (SDL_Init( SDL_INIT_EVERYTHING ) < 0) {
		std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
        return;
	}

    this->window = SDL_CreateWindow("CHIP8 Emulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DISPLAY_WIDTH, DISPLAY_HEIGHT, SDL_WINDOW_SHOWN);

    if (!this->window) {
        std::cout << "Error creating window: " << SDL_GetError() << std::endl;
        return;
    }

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);

    if (!this->renderer) {
        std::cout << "Error creating surface: " << SDL_GetError() << std::endl;
        return;
    }
}

Display::~Display() {
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
}

void Display::draw(const std::array<bool, WIDTH*HEIGHT>& pixels) {

    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            // find corresponding pixel
            bool pixel = pixels[(y * WIDTH) + x];

            if (pixel) {
                // Need to draw with main color
                SDL_SetRenderDrawColor(renderer, MAIN_COLOR.r, MAIN_COLOR.g, MAIN_COLOR.b, MAIN_COLOR.a);
            }

            else {
                // Need to draw with background color
                SDL_SetRenderDrawColor(renderer, BACKGROUND.r, BACKGROUND.g, BACKGROUND.b, BACKGROUND.a);
            }

            SDL_Rect rect;
            rect.x = x * SCALE;
            rect.y = y * SCALE;
            rect.w = SCALE;
            rect.h = SCALE;

            SDL_RenderFillRect(renderer, &rect);
        }
    }

    SDL_RenderPresent(renderer);

    return;
}

void Display::close() {
    SDL_DestroyWindow(this->window);
    SDL_Quit();

    return;
}