#include <SDL2/SDL.h>
#include <array>

const int SCALE = 30;
const int WIDTH = 64;
const int HEIGHT = 32;

const int DISPLAY_WIDTH = WIDTH * SCALE;
const int DISPLAY_HEIGHT = HEIGHT * SCALE;

const struct SDL_Color BACKGROUND = {0, 0, 0, 1};
const struct SDL_Color MAIN_COLOR = {255, 255, 255, 255};

class Display {
    public:
        Display();
        ~Display();
        void draw(const std::array<bool, WIDTH*HEIGHT>& pixels);
        void close();

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        int scale;
};