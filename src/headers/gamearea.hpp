#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include <SDL.h>
#include <vector>
#include "entity.hpp"

class GameArea {
public:

    std::vector<Entity*> entities; // Vector of all entities on the screen

    const int WIDTH;
    const int HEIGHT;

    // Init methods
    void initMap();

    // Entity management
    void addEntity(Entity* e);
    void collisionCheck();
    
    void update();

};


#endif
