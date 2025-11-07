#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "player.hpp"
#include <SDL.h>

class Controller {
public:

    bool quit; // Quit flag that can be accessed by external game loop

    Controller(Player* ref); // Constructor method that creates player reference
    
    // Helpers for controlling various facets
    void playerMovement(float dt, SDL_Event e);

    // Master method that passes poll event to all control methods
    void input(float dt, SDL_Event e);

private:

    Player* player; // Reference to player character held at all times

};



#endif