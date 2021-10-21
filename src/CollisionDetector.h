#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H

#include "Level.h"
#include "Entity.h"

#include <memory>

// A singular interface for aggregating collisions between entities and the level,
// or just entities with other entities.
class CollisionDetector {
public:
    CollisionDetector() = default;
    ~CollisionDetector() = default;

    void checkForLevelCollisionsOnXAxis(std::shared_ptr<Entity> entity, std::shared_ptr<Level> level);
    void checkForLevelCollisionsOnYAxis(std::shared_ptr<Entity> entity, std::shared_ptr<Level> level);

    void checkForEntityCollisions(std::vector<std::shared_ptr<Entity>> entityList);

private:

};

#endif