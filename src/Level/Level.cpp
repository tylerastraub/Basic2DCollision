#include "Level.h"

#include <iostream>

Level::Level() {
    // placeholder
    _tileMap = {
        {TileType::COLLIDE, TileType::COLLIDE, TileType::COLLIDE, TileType::COLLIDE, TileType::COLLIDE, TileType::COLLIDE, TileType::COLLIDE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::COLLIDE, TileType::COLLIDE},
        {TileType::COLLIDE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::COLLIDE, TileType::NONE, TileType::NONE, TileType::COLLIDE, TileType::COLLIDE},
        {TileType::COLLIDE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::COLLIDE, TileType::NONE, TileType::NONE, TileType::COLLIDE, TileType::COLLIDE},
        {TileType::COLLIDE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::COLLIDE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::COLLIDE, TileType::COLLIDE},
        {TileType::COLLIDE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::COLLIDE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::COLLIDE, TileType::COLLIDE},
        {TileType::COLLIDE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::COLLIDE, TileType::NONE, TileType::NONE, TileType::COLLIDE, TileType::COLLIDE},
        {TileType::COLLIDE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::COLLIDE, TileType::COLLIDE},
        {TileType::COLLIDE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::COLLIDE, TileType::NONE, TileType::COLLIDE, TileType::COLLIDE},
        {TileType::COLLIDE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::COLLIDE, TileType::COLLIDE},
        {TileType::COLLIDE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::COLLIDE, TileType::COLLIDE},
        {TileType::COLLIDE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::COLLIDE, TileType::COLLIDE, TileType::COLLIDE},
        {TileType::COLLIDE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::COLLIDE, TileType::COLLIDE},
        {TileType::COLLIDE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::COLLIDE, TileType::COLLIDE},
        {TileType::COLLIDE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::COLLIDE, TileType::COLLIDE},
        {TileType::COLLIDE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::COLLIDE, TileType::NONE, TileType::COLLIDE, TileType::COLLIDE},
        {TileType::COLLIDE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::COLLIDE, TileType::COLLIDE},
        {TileType::COLLIDE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::COLLIDE, TileType::COLLIDE},
        {TileType::COLLIDE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::COLLIDE, TileType::COLLIDE},
        {TileType::COLLIDE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::COLLIDE, TileType::COLLIDE},
        {TileType::COLLIDE, TileType::COLLIDE, TileType::COLLIDE, TileType::COLLIDE, TileType::COLLIDE, TileType::COLLIDE, TileType::COLLIDE, TileType::NONE, TileType::NONE, TileType::NONE, TileType::COLLIDE, TileType::COLLIDE}
    };
}

void Level::renderLevel(SDL_Renderer* renderer) {
    for(int x = 0; x < _tileMap.size(); ++x) {
        for(int y = 0; y < _tileMap[x].size(); ++y) {
            switch(_tileMap[x][y]) {
                case TileType::NONE:
                    break;
                case TileType::COLLIDE:
                    SDL_Rect tileRect;
                    tileRect.w = 16;
                    tileRect.h = 16;
                    tileRect.x = (x * 16) + _xOffset;
                    tileRect.y = (y * 16) + _yOffset;
                    SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
                    SDL_RenderDrawRect(renderer, &tileRect);
                    break;
                default:
                    break;
            }
        }
    }
}

void Level::setTile(int x, int y, TileType tile) {
    if(x < 0 || x > getTileMapWidth()) {
        std::cout << "Error: invalid X bounds when placing tile at X = " << x << std::endl;
    }
    else if(y < 0 || y > getTileMapHeight()) {
        std::cout << "Error: invalid Y bounds when placing tile at Y = " << y << std::endl;
    }
    else {
        _tileMap[x][y] = tile;
    }
    
}

void Level::setXOffset(int xOffset) {
    _xOffset = xOffset;
}
void Level::setYOffset(int yOffset) {
    _yOffset = yOffset;
}

// Returns the size of the wrapper tilemap vector
int Level::getTileMapWidth() {
    return _tileMap.size();
}

// Returns the size of the leftmost tile column
int Level::getTileMapHeight() {
    return _tileMap[0].size();
}

int Level::getXOffset() {
    return _xOffset;
}

int Level::getYOffset() {
    return _yOffset;
}

std::vector<std::vector<TileType>> Level::getTileMap() {
    return _tileMap;
}

int Level::getTileSize() {
    return TILE_SIZE;
}