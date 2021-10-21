#ifndef DUMMYSTATE_H
#define DUMMYSTATE_H

#include "State.h"
#include "Player.h"
#include "Level.h"
#include "CollisionDetector.h"

#include <unordered_map>
#include <memory>

class DummyState : public State {
public:
    DummyState() = default;
    ~DummyState();

    void init(SDL_Renderer* renderer) override;
    bool loadResources() override;
    void tick(int dTime) override;
    void render() override;

private:
    SDL_Texture* _texture;
    std::shared_ptr<Player> _player;
    std::shared_ptr<Level> _currentLevel;
    std::vector<std::shared_ptr<Entity>> _entityList;
    CollisionDetector _collisionDetector;
};

#endif