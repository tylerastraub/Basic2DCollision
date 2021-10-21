#include "Game.h"

#include <chrono>

Game::Game(const char * windowTitle) : _windowTitle(windowTitle) {}

Game::~Game() {}

bool Game::init() {
    bool windowCreatedSuccessfully = false;

    // SDL initialization
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL failed to initialize. SDL_Error: " << SDL_GetError() << std::endl;
    }
    else {
        if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            std::cout << "Warning: Linear texture filtering not enabled!" << std::endl;
        }
        if(!SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1")) {
            std::cout << "Warning: Vsync not enabled!" << std::endl;
        }
        // Window initialization
        _window = SDL_CreateWindow(_windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
        if(_window == NULL)
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else {
            // Render initialization
            _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
            if(_renderer == nullptr) {
                std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
            }
            else {
                SDL_RenderSetLogicalSize(_renderer, GAME_WIDTH, GAME_HEIGHT);
                // SDL_Image initialization
                int imgFlags = IMG_INIT_PNG;
                if(!(IMG_Init( imgFlags ) & imgFlags)) {
                    std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
                }
                else {
                    // State initialization
                    _currentState = new DummyState();
                    _currentState->init(_renderer);
                    if(!_currentState->loadResources()) {
                        std::cout << "Could not load resources!" << std::endl;
                    }
                    else {
                        windowCreatedSuccessfully = true;
                    }
                }
            }
        }
    }
    
    return windowCreatedSuccessfully;
}

void Game::startGameLoop() {
    SDL_Event e;
    auto startTime = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds dTime = std::chrono::milliseconds(0); // deltaTime
    Uint32 millisecondCount = 0;
    Uint32 frames = 0;
    while(_exitFlag == false) {
        // Event Handling
        while(SDL_PollEvent(&e) != 0) {
            if(e.type == SDL_QUIT) {
                _exitFlag = true;
            }
            else if(e.type == SDL_KEYDOWN) {
                if(e.key.keysym.sym == SDLK_ESCAPE) {
                    _exitFlag = true;
                }
            }
        }

        // ticks are time based
        dTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - startTime);
        _currentState->tick(dTime.count());
        startTime = std::chrono::high_resolution_clock::now();
        millisecondCount += dTime.count();
        _currentState->render();
        frames++;

        if(millisecondCount >= 1000) {
            std::cout << "FPS: " << frames << std::endl;
            frames = 0;
            millisecondCount = 0;
        }
    }

    exit();
}

void Game::exit() {
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);

    _window = nullptr;
    _renderer = nullptr;

    IMG_Quit();
    SDL_Quit();
}