#include "Window.h"
#include <iostream>

//CONSTRUCTOR

Window::Window(const int& rows, const int& cols)
{
    window = SDL_CreateWindow(
        "Bullet Hell",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        cols,
        rows,
        0);

    if (window == nullptr) {
        std::cout << "ERROR::WINDOW_CREATION_FAILED" << std::endl;
        exit(EXIT_FAILURE);
    }
}

Window::~Window()
{
    SDL_DestroyWindow(window);
    window = nullptr;
}

//GETTER

SDL_Window* Window::getWindow()
{
    return window;
}
