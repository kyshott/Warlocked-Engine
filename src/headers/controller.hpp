#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "player.hpp"
#include <SDL.h>

/**
 * @brief Controller class for input handling using SDL.
 * 
 * Uses SDL to handle inputs and update all controllable objects accordingly. Currently only supports movement for one object, but future updates may allow for multiple objects to be controlled.
 * Only one controller object should exist at any given time to avoid input conflicts (though theoretically multiple controllers would not cause issues). The controller object persists
 * between area transitions and exists upon engine startup.
 * 
 * Currently only takes one argument which is a reference to the player object to be controlled.
 * 
 * @param ref Pointer to the player object to be controlled. 
 */
class Controller {
public:

    // Quit flag that can be accessed by external game loop. Should this be in the controller or somewhere else?
    bool quit;

    /**
     * @brief Constructor for Controller class.
     * 
     * Initializes the Controller with a reference to the Player object it will control. Future updates may allow for multiple objects to be controlled if it is ever needed.
     * 
     * @param ref Pointer to the player object to be controlled.
     */
    Controller(Player* ref);
    
    /**
     * @brief Helper method to manage player movement based on input events.
     * 
     * Processes SDL events to update the player's position and state according to input. This method is called within the main input handling loop to reduce clutter.
     * 
     * @param dt Delta time.
     * @param e SDL_Event to process. Exclusively used for player positional movement.
     */
    void playerMovement(float dt, SDL_Event e);

    /**
     * @brief Main input handling method.
     * 
     * Called within the game loop - processes all input events and updates objects and game state accordingly. With each subsequent feature added to the game, this method will
     * grow to accomodate those features.
     * 
     * @param dt Delta time.
     * @param e SDL_Event to process. The event will be run through all possible input checks and will register if applicable. Hopefully not too inefficient.
     */
    void input(float dt, SDL_Event e);

private:

    // Reference to the player object to be controlled.
    Player* player;

};



#endif