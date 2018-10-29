#ifndef Game_hpp
#define Game_hpp
#include "SDL.h"
#include <stdio.h>

class Game
{
public:
    Game();
    ~Game();

    void init(const char* title, int x, int y, int width, int height, int flags);
    
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running();

private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif // Game_hpp