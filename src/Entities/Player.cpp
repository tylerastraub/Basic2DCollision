#include "Player.h"

#include <iostream>
#include <math.h>

Player::Player() {
    _entityRect = new SDL_Rect();
}

// Initialize with a preexisiting SDL_Rect
Player::Player(SDL_Rect* playerRect) {
    _entityRect = playerRect;
}

void Player::handleInput(const Uint8* currentKeyStates) {
    _up = (currentKeyStates[SDL_SCANCODE_UP]) ? true : false;
    _down = (currentKeyStates[SDL_SCANCODE_DOWN]) ? true : false;
    _left = (currentKeyStates[SDL_SCANCODE_LEFT]) ? true : false;
    _right = (currentKeyStates[SDL_SCANCODE_RIGHT]) ? true : false;
}

void Player::tick(int dTime) {
    float timescale = (float) dTime / 1000.f;

    if(_left) {
        _dX -= _acceleration * timescale;
        if(std::abs(_dX) > _maxSpeed * timescale) {
            int coefficient = (_dX > 0) ? 1 : -1;
            _dX = _maxSpeed * coefficient * timescale;
        }
    }
    if(_right) {
        _dX += _acceleration * timescale;
        // this might be overkill
        if(std::abs(_dX) > _maxSpeed * timescale) {
            int coefficient = (_dX > 0) ? 1 : -1;
            _dX = _maxSpeed * coefficient * timescale;
        }
    }
    if(!_left && !_right) {
        _dX = 0.f;
    }

    if(_touchingGround && _up) {
        _dY = _jumpPower * -1;
        _touchingGround = false;
    }
}