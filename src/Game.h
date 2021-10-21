#ifndef GAME_H
#define GAME_H

#include "SDL_image.h"
#include <iostream>

#include "ResourceHandler/ResourceHandler.h"
#include "States/State.h"
#include "States/DummyState.h"

class Game {
public:
    Game(const char * windowTitle);
    ~Game();

    bool init();
    void startGameLoop();
    void exit();

private:
    const char * _windowTitle;

    const int GAME_WIDTH = 320;
    const int GAME_HEIGHT = 180;

    int _screenWidth = 1280;
    int _screenHeight = 720;

    SDL_Window* _window = nullptr;
    SDL_Renderer* _renderer = nullptr;

    bool _exitFlag = false;

    State* _currentState = nullptr;
};

#endif