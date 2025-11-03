#ifndef GAME_AREA_H
#define GAME_AREA_H

#include <SDL.h>
#include <vector>
#include "entity.hpp"
#include "memory"
#include <tinytmx.hpp>
#include "textureloader.hpp"

class GameArea {
public:

    //TODO: Come up with logic for freeing entities and objects that take up memory in each area

    // Use smart pointers for automatic memory management. Entities go into smart pointer vectors, areas go into smart pointer vectors, etc etc

    SDL_Texture* tileset;

    std::vector<std::unique_ptr<Entity>> entities;

    GameArea(int idk);

    // Area state
    void initMap(std::string mapFile, SDL_Renderer* renderer);
    void saveState(); // Include memory freeing as part of this method
    void loadState();

    // Entity management / general functionality
    void addEntity(Entity e);
    void areaUpdate(float dt, SDL_Renderer* renderer);
    void layerRender(tinytmx::Map* map, SDL_Texture* tileTex, const tinytmx::Tileset* tileset, SDL_Renderer* renderer); // Render layers of the map from tilemap. Helper function

};


#endif
