#include "headers/controller.hpp"
#include "headers/player.hpp"
#include <SDL.h>

Controller::Controller(Player* ref) {
    player = ref;
    quit = false;
}

void Controller::playerMovement(float dt, SDL_Event e) {

        player->handleMoveEvent(e);
}

void Controller::input(float dt, SDL_Event e) {
    while (SDL_PollEvent(&e) != 0) {
        // Quit signal - add method later to handle this
		if (e.type == SDL_QUIT) {
			quit = true;
	    }

        playerMovement(dt, e);
    }

}