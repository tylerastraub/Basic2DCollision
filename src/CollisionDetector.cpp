#include "CollisionDetector.h"

#include <iostream>
#include <math.h>
#include <queue>

struct TileCoords {
    int x;
    int y;
    int dist;

    TileCoords(int x, int y, int dist) : x(x), y(y), dist(dist) {}

    bool operator<(const TileCoords& rhs) const
    {
        return dist < rhs.dist;
    }
};

void CollisionDetector::checkForLevelCollisionsOnXAxis(std::shared_ptr<Entity> entity, std::shared_ptr<Level> level) {
    std::vector<std::vector<TileType>> tileMap = level->getTileMap();
    int tileSize = level->getTileSize();
    int xOffset = level->getXOffset();
    int yOffset = level->getYOffset();
    SDL_Rect* entityRect = entity->getEntityRect();
    SDL_Point topLeftTileCoord, bottomRightTileCoord;
    topLeftTileCoord.x = entityRect->x / tileSize;
    topLeftTileCoord.y = entityRect->y / tileSize;
    bottomRightTileCoord.x = (entityRect->x + entityRect->w - 1) / tileSize;
    bottomRightTileCoord.y = (entityRect->y + entityRect->h - 1) / tileSize;

    std::priority_queue<TileCoords> tileCollisions;
    if(entity->getDX() < 0) {
        // Entity is moving left - get all tiles to left
        for(int y = topLeftTileCoord.y; y <= bottomRightTileCoord.y; ++y) {
            if(topLeftTileCoord.x >= 0 && bottomRightTileCoord.x < level->getTileMapWidth() &&
               y >= 0 && y < level->getTileMapHeight()) {
                if(tileMap[topLeftTileCoord.x][y] == TileType::COLLIDE) {
                    // Since all the tiles we are looking at share the same x coordinates,
                    // we can simply just calculate distance on the y axis to find the
                    // closest tile.
                    int dist = entityRect->y - (y * tileSize);
                    TileCoords t(topLeftTileCoord.x * tileSize, y * tileSize, std::abs(dist));
                    tileCollisions.emplace(t);
                }
            }
        }

        // If we have a collision:
        if(!tileCollisions.empty()) {
            TileCoords closestTile = tileCollisions.top();
            // then place entity as close as possible to right of tile
            entity->setPosition(closestTile.x + tileSize, entityRect->y);
            entity->setDX(0);
        }
    }
    else if(entity->getDX() > 0) {
        // Entity is moving right - get all tiles to right
        for(int y = topLeftTileCoord.y; y <= bottomRightTileCoord.y; ++y) {
            if(topLeftTileCoord.x >= 0 && bottomRightTileCoord.x < level->getTileMapWidth() &&
               y >= 0 && y < level->getTileMapHeight()) {
                if(tileMap[bottomRightTileCoord.x][y] == TileType::COLLIDE) {
                    // Since all the tiles we are looking at share the same x coordinates,
                    // we can simply just calculate distance on the y axis to find the
                    // closest tile.
                    int dist = entityRect->y - (y * tileSize);
                    TileCoords t(bottomRightTileCoord.x * tileSize, y * tileSize, std::abs(dist));
                    tileCollisions.emplace(t);
                }
            }
        }

        // If we have a collision:
        if(!tileCollisions.empty()) {
            TileCoords closestTile = tileCollisions.top();
            // then place entity as close as possible to left of tile
            entity->setPosition(closestTile.x - entityRect->w, entityRect->y);
            entity->setDX(0);
        }
    }
}

void CollisionDetector::checkForLevelCollisionsOnYAxis(std::shared_ptr<Entity> entity, std::shared_ptr<Level> level) {
    std::vector<std::vector<TileType>> tileMap = level->getTileMap();
    int tileSize = level->getTileSize();
    int xOffset = level->getXOffset();
    int yOffset = level->getYOffset();
    SDL_Rect* entityRect = entity->getEntityRect();
    SDL_Point topLeftTileCoord, bottomRightTileCoord;
    topLeftTileCoord.x = entityRect->x / tileSize;
    topLeftTileCoord.y = entityRect->y / tileSize;
    bottomRightTileCoord.x = (entityRect->x + entityRect->w - 1) / tileSize;
    bottomRightTileCoord.y = (entityRect->y + entityRect->h - 1) / tileSize;

    std::priority_queue<TileCoords> tileCollisions;
    if(entity->getDY() < 0) {
        // Entity is moving up - get all tiles to top
        for(int x = topLeftTileCoord.x; x <= bottomRightTileCoord.x; ++x) {
            if(x >= 0 && x < level->getTileMapWidth() &&
               topLeftTileCoord.y >= 0 && bottomRightTileCoord.y < level->getTileMapHeight()) {
                if(tileMap[x][topLeftTileCoord.y] == TileType::COLLIDE) {
                    // Since all the tiles we are looking at share the same y coordinates,
                    // we can simply just calculate distance on the x axis to find the
                    // closest tile.
                    int dist = entityRect->x - (x * tileSize);
                    TileCoords t(x * tileSize, topLeftTileCoord.y * tileSize, std::abs(dist));
                    tileCollisions.emplace(t);
                }
            }
        }

        // If we have a collision:
        if(!tileCollisions.empty()) {
            TileCoords closestTile = tileCollisions.top();
            // then place entity as close as possible to bottom of tile
            entity->setPosition(entityRect->x, closestTile.y + tileSize);
            entity->setDY(0);
        }
    }
    else if(entity->getDY() > 0) {
        // Entity is moving down - get all tiles to bottom
        for(int x = topLeftTileCoord.x; x <= bottomRightTileCoord.x; ++x) {
            if(x >= 0 && x < level->getTileMapWidth() &&
               topLeftTileCoord.y >= 0 && bottomRightTileCoord.y < level->getTileMapHeight()) {
                if(tileMap[x][bottomRightTileCoord.y] == TileType::COLLIDE) {
                    // Since all the tiles we are looking at share the same y coordinates,
                    // we can simply just calculate distance on the x axis to find the
                    // closest tile.
                    int dist = entityRect->x - (x * tileSize);
                    TileCoords t(x * tileSize, bottomRightTileCoord.y * tileSize, std::abs(dist));
                    tileCollisions.emplace(t);
                }
            }
        }

        // If we have a collision:
        if(!tileCollisions.empty()) {
            TileCoords closestTile = tileCollisions.top();
            // then place entity as close as possible to top of tile
            entity->setPosition(entityRect->x, closestTile.y - entityRect->h);
            entity->setDY(0);
            entity->setTouchingGround(true);
        }
        else {
            entity->setTouchingGround(false);
        }
    }
}

// TODO: Not implemented
void CollisionDetector::checkForEntityCollisions(std::vector<std::shared_ptr<Entity>> entityList) {}