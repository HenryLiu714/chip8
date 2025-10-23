#include "display.h"

#include <iostream>
#include <stdlib.h>
#include <array>
#include <chrono>
#include <thread>

int main() {
    Display display = Display();

    std::array<uint8_t, 64*32> arr;

    display.draw(arr);

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    display.close();
}