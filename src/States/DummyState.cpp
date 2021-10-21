#include "DummyState.h"

#include <iostream>

DummyState::~DummyState() {
    SDL_DestroyTexture(_texture);
    _texture = nullptr;
}

void DummyState::init(SDL_Renderer* renderer) {
    _renderer = renderer;
    _currentLevel = std::make_shared<Level>();
    _player = std::make_shared<Player>();
    _player->setPosition(160, 90);
    _player->setSize(16, 32);
    _entityList.push_back(_player);
}

bool DummyState::loadResources() {
    bool resourcesLoadedSuccessfully = true;

    _texture = _resourceHandler.loadTexture(_renderer, "res\\tape_wheel.png");
    if(_texture == nullptr) {
        resourcesLoadedSuccessfully = false;
    }

    return resourcesLoadedSuccessfully;
}

void DummyState::tick(int dTime) {
    // Process keyboard presses
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    _player->handleInput(currentKeyStates);
    for(auto e : _entityList) {
        e->applyGravity(dTime);
        e->tick(dTime);
        // Step X, check for X collisions
        e->updatePosition(e->getDX(), 0.f);
        _collisionDetector.checkForLevelCollisionsOnXAxis(e, _currentLevel);
        // Step Y, check for Y collisions
        e->updatePosition(0.f, e->getDY());
        _collisionDetector.checkForLevelCollisionsOnYAxis(e, _currentLevel);
    }
}

void DummyState::render() {
    // Clear screen
    SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x00, 0xFF );
    SDL_RenderClear(_renderer);
    
    // Draw foreground
    _currentLevel->renderLevel(_renderer);
    // SDL_RenderCopy(_renderer, _texture, NULL, NULL);
    SDL_SetRenderDrawColor(_renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(_renderer, _player->getEntityRect());
    SDL_RenderPresent(_renderer);
}