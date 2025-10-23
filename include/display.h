#pragma once

#include <SDL2/SDL.h>
#include <array>

const int SCALE = 10;
const int WIDTH = 64;
const int HEIGHT = 32;

class Display {
    public:
        Display(int scale=SCALE);
        ~Display();
        void draw(const std::array<uint8_t, WIDTH*HEIGHT>& pixels);
        void close();

    private:
        SDL_Window* window;
        SDL_Surface* surface;
};