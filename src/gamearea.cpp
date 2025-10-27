#include "headers/gamearea.hpp"
#include "memory"

void GameArea::initMap() {
    // Initialize the game area, load map data, etc... loaded from file
    // Iterate through all entities stored in the area from loadState and initialize them 

    loadState();

    // Initialize map - probably entails loading a tilemap texture or something simple since entity management is done in loadState()
}

void GameArea::saveState() {
    // Save the current state of the game area, entities, etc... to a file

    // Save entity positional and other instance data to something

    entities.clear(); // Free up memory for entities
}

void GameArea::loadState() {
    // Load the state of the game area that was previously loaded from saveState...
    
    // Load entity from data file (whatever it is)
    // Call addEntity() for each entity in this data file
}

// I can either pass a unique pointer as a parameter and add it to the vector, or pass a raw pointer and convert it to a unique pointer here... idk which is better
void GameArea::addEntity(Entity* e) {

    entities.push_back(std::make_unique<Entity>(e));

}

// Updates everything in the game area, including entity positions, rendering, collision etc
void GameArea::areaUpdate(float dt, SDL_Renderer* renderer) {

    for (auto& entity : entities) {
        entity->update(renderer, dt);
        //entity->collider(dt, entities);
    }
   
}

