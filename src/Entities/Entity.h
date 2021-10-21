#ifndef ENTITY_H
#define ENTITY_H

#include "SDL.h"

class Entity {
public:
    Entity() = default;
    ~Entity();

    virtual void handleInput(const Uint8* currentKeyStates) = 0;
    virtual void tick(int dTime) = 0;

    void updatePosition(float dX, float dY);
    void revertToLastXPos();
    void revertToLastYPos();
    void applyGravity(int dTime);

    // Setters
    void setEntityRect(SDL_Rect* entityRect);
    void setPosition(float x, float y);
    void setSize(int w, int h);
    void setAcceleration(float acceleration);
    void setMaxSpeed(float maxSpeed);
    void setTouchingGround(bool isTouchingGround);
    void setDX(int dX);
    void setDY(int dY);

    // Getters
    SDL_Rect* getEntityRect();
    float getXPos();
    float getYPos();
    float getLastXPos();
    float getLastYPos();
    float getDX();
    float getDY();
    bool isTouchingGround();
    float getEntityGravity();
    float getCurrentTimescale();

protected:
    float _xPos = 0.f;
    float _yPos = 0.f;
    float _lastXPos = 0.f;
    float _lastYPos = 0.f;
    float _dX = 0.f;
    float _dY = 0.f;

    float _currentTimescale = 0.f;

    SDL_Rect* _entityRect;
    // Max speed in units per second
    float _maxSpeed = 200.f;
    // Acceleration is how much the entity's speed increases per tick relative to time.
    // If you want to take 1 second to get to _maxSpeed, make _acceleration 1/60 of it.
    float _acceleration = 50.f;

    float _worldGravity = 15.f;
    // Does not scale linearly, but 4.f is a little more than 2 blocks of jump power
    // with default gravity of 15.f.
    float _jumpPower = 4.f;

    bool _touchingGround = false;

};

#endif