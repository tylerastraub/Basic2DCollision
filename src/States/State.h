#ifndef STATE_H
#define STATE_H

#include "SDL.h"

#include "ResourceHandler.h"

class State {
public:
    State() = default;
    ~State() = default;

    // Virtual methods
    virtual void init(SDL_Renderer* renderer) = 0;
    virtual bool loadResources() = 0;
    virtual void tick(int dTime) = 0;
    virtual void render() = 0;

    void setNextState(State* state);
    State* getNextState();

protected:
    ResourceHandler _resourceHandler;
    SDL_Renderer* _renderer;

private:
    State* _nextState = nullptr;

};

#endif