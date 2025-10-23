#include "display.h"

#include <iostream>
#include <stdlib.h>
#include <array>
#include <chrono>
#include <thread>

int main() {
    Display display = Display();

    std::array<bool, 64*32> arr = {0};

    for (int i = 0; i < 32 * 64; i+=4) {
        arr[i] = 1;
    }

    display.draw(arr);

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    display.close();
}