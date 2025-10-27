#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include <SDL.h>
#include <vector>
#include "entity.hpp"
#include "memory"
#include "gamearea.hpp"

class GameWorld {
    public:

        GameArea currentArea; // Current active game area
        std::vector<std::unique_ptr<GameArea>> areas;

        void initWorld();

        void switchArea();

};

#endif