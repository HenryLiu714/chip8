#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <vector>

#include "chip8.h"

const int GRID_WIDTH = 64;
const int GRID_HEIGHT = 32;
const int PIXEL_SIZE = 10;  // scaling factor

int main() {
    const int PIXEL_SIZE = 10; // scaling factor
    SDL_Window* window = SDL_CreateWindow(
        "CHIP-8",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        64 * PIXEL_SIZE, 32 * PIXEL_SIZE,
        SDL_WINDOW_SHOWN
    );

    SDL_Texture* texture = SDL_CreateTexture(renderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_STREAMING,
        64, 32);

    Chip8 chip8;
    chip8.LoadROM("roms/ibm.ch8");

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = true;
        }

        chip8.Display(renderer, texture); // <— Your display function

        SDL_Delay(1);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
