#include "Entity.h"

#include <iostream>

Entity::~Entity() {
    if(_entityRect) delete _entityRect;
}

void Entity::updatePosition(float dX, float dY) {
    _lastXPos = _xPos;
    _lastYPos = _yPos;
    _xPos += dX;
    _yPos += dY;
    _entityRect->x = _xPos;
    _entityRect->y = _yPos;
}

void Entity::revertToLastXPos() {
    _xPos = _lastXPos;
    _entityRect->x = _xPos;
}

void Entity::revertToLastYPos() {
    _yPos = _lastYPos;
    _entityRect->y = _yPos;
}

void Entity::applyGravity(int dTime) {
    float timescale = (float) dTime / 1000.f;
    _dY += _worldGravity * timescale;
    _currentTimescale = timescale;
}

void Entity::setEntityRect(SDL_Rect* entityRect) {
    _entityRect = entityRect;
}

// Set entity's absolute position
void Entity::setPosition(float x, float y) {
    _lastXPos = _xPos;
    _lastYPos = _yPos;
    _xPos = x;
    _yPos = y;
    _entityRect->x = x;
    _entityRect->y = y;
}

void Entity::setSize(int w, int h) {
    _entityRect->w = w;
    _entityRect->h = h;
}

void Entity::setAcceleration(float acceleration) {
    _acceleration = acceleration;
}

void Entity::setMaxSpeed(float maxSpeed) {
    _maxSpeed = maxSpeed;
}

void Entity::setTouchingGround(bool isTouchingGround) {
    _touchingGround = isTouchingGround;
}

void Entity::setDX(int dX) {
    _dX = dX;
}

void Entity::setDY(int dY) {
    _dY = dY;
}

// Return data structure containing entity's SDL_Rect
SDL_Rect* Entity::getEntityRect() {
    return _entityRect;
}

float Entity::getXPos() {
    return _xPos;
}

float Entity::getYPos() {
    return _yPos;
}

float Entity::getLastXPos() {
    return _lastXPos;
}

float Entity::getLastYPos() {
    return _lastYPos;
}

float Entity::getDX() {
    return _dX;
}

float Entity::getDY() {
    return _dY;
}

bool Entity::isTouchingGround() {
    return _touchingGround;
}

float Entity::getEntityGravity() {
    return _worldGravity;
}

float Entity::getCurrentTimescale() {
    return _currentTimescale;
}