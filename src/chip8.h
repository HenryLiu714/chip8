#ifndef CHIP8_H
#define CHIP8_H

#include <cstdint>
#include <stdexcept>
#include <SDL.h>
#include <string>

class Chip8 {
    public:
        uint8_t registers[16]{};
        uint8_t mem[4096]{};
        uint16_t index_register{};
        uint16_t program_counter{0x200};
        uint16_t stack[16]{};
        uint8_t stack_pointer{};
        uint8_t delay_timer{};
        uint8_t sound_timer{};
        uint32_t video[64 * 32]{};
        uint8_t keys[16]{};
        uint8_t op_code{};

        bool LoadROM(char const* filename);

        void Cycle();

        short Fetch();

        void DecodeAndExecute(short instr);

        void Display(SDL_Renderer* renderer, SDL_Texture* texture);
    };

#endif // !CHIP8_H