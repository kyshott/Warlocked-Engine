#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include <SDL.h>
#include <vector>
#include "entity.hpp"
#include "memory"
#include "gamearea.hpp"

/**
 * @brief The "world" class that contains all areas.
 * 
 * A class to contain the collection of all available "areas" in the game. Contains the mapping for all areas and the order in which they are traversed. 
 * Acts as an abstraction layer/machine to transition smoothly between areas. 
 */
class GameWorld {
    public:

        // Current active Game Area as specified by the mapping.
        GameArea currentArea;

        // Unique pointer to all available areas - will be removed later as a unique pointer is not necessary here since there is a 
        // specific "freeing" class for GameArea.
        std::vector<std::unique_ptr<GameArea>> areas;

        /**
         * @brief Initializes the game world.
         * 
         * Initializes the game world and loads the mapping for all areas. 
         * Loads all other necessary resources for area maintenance and chunking.
         */
        void initWorld();

        /**
         * @brief Switches the active game area.
         * 
         * Switches over to the next active game area according to a signal sent from the existing game area class. 
         * Existing game area supplies the index for the next area to be loaded, to which the world responds by saving the current area state,
         * freeing resources, then loading the next area at the index according to the mapping.
         * 
         * @param idx Index for next area.
         */
        void switchArea(int idx);

};

#endif