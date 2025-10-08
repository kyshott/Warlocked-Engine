#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include <SDL.h>
#include <vector>
#include "entity.hpp"

class GameArea {
public:

    //TODO: Come up with logic for freeing entities and objects that take up memory in each area

    // Use smart pointers for automatic memory management. Entities go into smart pointer vectors, areas go into smart pointer vectors, etc etc

    std::vector<Entity*> entities; // Vector of all entities on the screen

    const int WIDTH;
    const int HEIGHT;

    // Area state
    void initMap();
    void saveState(); // Include memory freeing as part of this method

    // Entity management / general functionality
    void addEntity(Entity* e);
    void areaUpdate(float dt, SDL_Renderer* renderer);

};


#endif
