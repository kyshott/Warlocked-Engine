#include "headers/gamearea.hpp"

void GameArea::initMap() {
    // Initialize the game area, load map data, etc... loaded from file
}

void GameArea::saveState() {
    // Save the current state of the game area, entities, etc... to a file
}

void GameArea::addEntity(Entity* e) {
    entities.push_back(e);
}

// Updates everything in the game area, including entity positions, rendering, collision etc
void GameArea::areaUpdate(float dt, SDL_Renderer* renderer) {
   
}

