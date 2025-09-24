#include <cstring>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>

#include "chip8.h"

void Chip8::Cycle() {
    short instr = Fetch();
    DecodeAndExecute(instr);
}

short Chip8::Fetch() {
    // Fetch from current pc
    short instr;

    std::memcpy(&instr, &mem[program_counter], sizeof(instr));

    program_counter += 2; // Increment to next instruction

    return instr;
}

void Chip8::DecodeAndExecute(short instr) {
     short nibble = (instr >> 12);
     short X = (instr >> 8) & 0x0F; // Second nibble
     short Y = (instr >> 4) & 0x0F; // Third nibble
     short N = instr & 0x0F; // Last nibble
     short NN = instr & 0xFF; // Last 2 nibbles
     short NNN = instr & 0x0FFF; // Last 3 nibbles


}

void Chip8::Display(SDL_Renderer* renderer, SDL_Texture* texture) {
    uint32_t* pixels;
    int pitch;

    if (SDL_LockTexture(texture, nullptr, (void**)&pixels, &pitch) == 0) {
        for (int y = 0; y < 32; ++y) {
            for (int x = 0; x < 64; ++x) {
                uint8_t pixel = video[y * 64 + x];
                // uint32_t color = pixel ? 0xFFFFFFFF : 0x000000FF; // white/black
                uint32_t color = 0xFFFFFFFF;
                pixels[y * (pitch / 4) + x] = color;
            }
        }
        SDL_UnlockTexture(texture);
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);
}

bool Chip8::LoadROM(char const* filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::ate);

    std::streamsize size = file.tellg(); // Get size of array
    file.seekg(0, std::ios::beg);

    if (size > (4096 - 0x200)) {
        std::cerr << "ROM too large to fit in memory!" << std::endl;
        return false;
    }

    std::vector<char> buffer(size);

    if (!file.read(buffer.data(), size)) {
        std::cerr << "Error reading ROM" << std::endl;
        return false;
    }

    // Read from buffer into memory
    for (int i = 0; i < size; i++) {
        mem[0x200 + i] = static_cast<uint8_t>(buffer[i]);
    }

    std::cout << "success";

    return true;

}