#include "headers/gamearea.hpp"
#include <memory>
#include "headers/player.hpp"
#include "headers/textureloader.hpp"
#include "headers/tilemaptools.hpp"
#include <tinytmx.hpp>
#include <iostream>

GameArea::GameArea(std::string mapFile, SDL_Renderer* renderer, Player* ref) {

    player = ref;

    // Initialize map and its texture.
    map = std::make_unique<tinytmx::Map>();
    map->ParseFile(mapFile);
    mapTexture = initMapTexture(renderer, map.get());

    // Create tileset texture then render layer 0 map
    tileTex = createTileSetTexture(renderer, map.get());
    mapTexture = renderMap(map.get(), tileTex, mapTexture, map->GetTileset(0), renderer);

}

void GameArea::areaUpdate(float dt, SDL_Renderer* renderer){

    SDL_RenderCopy(renderer, mapTexture, nullptr, nullptr);

    player->update(renderer, dt);

    for (auto& entity : entities) {
        entity->update(renderer, dt);
        entity->collider(dt, entities);
    }
   
}

void GameArea::saveState() {
    // Save the current state of the game area, entities, etc... to a file

    // Save entity positional and other instance data to something

    entities.clear(); // Free up memory for entities

    SDL_DestroyTexture(tileTex);
    SDL_DestroyTexture(mapTexture);
}

void GameArea::loadState() {
    // Load the state of the game area that was previously loaded from saveState...
    
    // Load entity from data file (whatever it is)
    // Call addEntity() for each entity in this data file
}

// I can either pass a unique pointer as a parameter and add it to the vector, or pass a raw pointer and convert it to a unique pointer here... idk which is better
void GameArea::addEntity(Entity e) {

   entities.push_back(std::make_unique<Entity>(e));

}
