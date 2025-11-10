#include "headers/gameworld.hpp"

void GameWorld::switchArea(int idx) {
    // Logic for switching between different game areas
    // Update currentArea to point to the new area

    currentArea.saveState();

    // Switch logic here...

}

void GameWorld::initWorld() {
    // Initialize game world by loading from file. More than likely probably one of the most important functions as it loads the entire game
}
