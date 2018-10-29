#include "Game.hpp"
#include <iostream>

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const char * title, int x, int y, int width, int height, int flags)
{
    if (!SDL_Init(SDL_INIT_EVERYTHING))
    {
        std::cout << "Subsystems Initialized..." << std::endl;

        this->window = SDL_CreateWindow(title, x, y, width, height, flags);

        if (window)
            std::cout << "Window Created..." << std::endl;

        this->renderer = SDL_CreateRenderer(this->window, -1, 0);
        SDL_SetRenderDrawColor(this->renderer, 0, 0, 255, 255);

        if (renderer)
            std::cout << "Renderer Created..." << std::endl;

        this->isRunning = true;
    }
    else
        this->isRunning = false;
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        this->isRunning = false;
        break;
    default:
        break;
    }
}

void Game::update()
{
    Uint8 r = 0, g = 0, b = 0, a = 0;

    SDL_GetRenderDrawColor(this->renderer, &r, &g, &b, &a);
    
    b++;

    if (b > 255)
        b = 0;

    SDL_SetRenderDrawColor(this->renderer, r, g, b, a);
}

void Game::render()
{
    SDL_RenderClear(this->renderer);
    SDL_RenderPresent(this->renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
    SDL_Quit();
    std::cout << "Clean Complete..." << std::endl;
}

bool Game::running()
{
    return this->isRunning;
}
