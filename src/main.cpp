#define SDL_MAIN_HANDLED
#include "Game.hpp"

Game *game = nullptr;

int main(int argc, char* argv[])
{
    game = new Game();

    game->init("Doodily Doo", 0, 0, 500, 500, 0);

    while (game->running())
    {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();

    return 0;
}