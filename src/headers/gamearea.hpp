#ifndef GAME_AREA_H
#define GAME_AREA_H

#include <SDL.h>
#include <vector>
#include "entity.hpp"
#include "memory"

class GameArea {
public:

    //TODO: Come up with logic for freeing entities and objects that take up memory in each area

    // Use smart pointers for automatic memory management. Entities go into smart pointer vectors, areas go into smart pointer vectors, etc etc

    std::vector<std::unique_ptr<Entity>> entities;

    const int WIDTH;
    const int HEIGHT;

    // Area state
    void initMap();
    void saveState(); // Include memory freeing as part of this method
    void loadState();

    // Entity management / general functionality
    void addEntity(Entity* e);
    void areaUpdate(float dt, SDL_Renderer* renderer);
    void layerRender(); // Render layers of the map from tilemap. Helper function

};


#endif
