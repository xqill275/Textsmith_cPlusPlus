#pragma once

#include <iostream>
#include <sstream>
#include <string>

class InputHandler {
public:
    template <typename T>
    T getInput(const std::string& prompt) {
        T value;
        std::string input;

        while (true) {
            std::cout << prompt;
            std::getline(std::cin, input);
            std::stringstream ss(input);

            if (ss >> value && ss.eof()) {
                return value;
            }

            std::cout << "Invalid input. Please try again.\n";
        }
    }
};