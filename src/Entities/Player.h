#ifndef PLAYER_H
#define PLAYER_H

#include "SDL.h"
#include "Entity.h"

class Player : public Entity {
public:
    Player();
    Player(SDL_Rect* playerRect);
    ~Player() = default;

    void handleInput(const Uint8* currentKeyStates) override;
    void tick(int dTime) override;

private:

    // Input bools
    bool _up = false;
    bool _down = false;
    bool _left = false;
    bool _right = false;
};

#endif