#include <display.h>

#include <iostream>
#include <SDL2/SDL.h>

Display::Display(int scale) {
    int display_width = WIDTH * scale;
    int display_height = HEIGHT * scale;

    if (SDL_Init( SDL_INIT_EVERYTHING ) < 0) {
		std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
        return;
	}

    this->window = SDL_CreateWindow("CHIP8 Emulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, display_width, display_height, SDL_WINDOW_SHOWN);

    if (!this->window) {
        std::cout << "Error creating window: " << SDL_GetError() << std::endl;
        return;
    }

    this->surface = SDL_GetWindowSurface(this->window);

    if (!this->surface) {
        std::cout << "Error creating surface: " << SDL_GetError() << std::endl;
        return;
    }
}

Display::~Display() {
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
}

void Display::draw(const std::array<uint8_t, WIDTH*HEIGHT>& pixels) {
    SDL_FillRect(this->surface, NULL, SDL_MapRGB(this->surface->format, 255, 0, 255 ));
    SDL_UpdateWindowSurface(this->window);

    return;
}

void Display::close() {
    SDL_DestroyWindow(this->window);
    SDL_Quit();

    return;
}