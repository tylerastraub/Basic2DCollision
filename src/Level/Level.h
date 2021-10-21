#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "SDL.h"

enum TileType {
    NONE = 0,
    COLLIDE = 1
};

class Level {
public:
    Level();
    ~Level() = default;

    void renderLevel(SDL_Renderer* renderer);

    // Setters
    void setTile(int x, int y, TileType tileType);
    void setXOffset(int xOffset);
    void setYOffset(int yOffset);

    // Getters
    int getTileMapWidth();
    int getTileMapHeight();
    int getXOffset();
    int getYOffset();
    std::vector<std::vector<TileType>> getTileMap();
    int getTileSize();

private:
    std::vector<std::vector<TileType>> _tileMap;

    // Offset for both rendering purposes and collision purposes
    int _xOffset = 0;
    int _yOffset = 0;

    const int TILE_SIZE = 16;
};

#endif