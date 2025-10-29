#include "headers/player.hpp"
#include "headers/textureloader.hpp"
#include <iostream>
#include <stdlib.h>
#include <algorithm>

//Handle key events in the event queue
void Player::handleMoveEvent(const SDL_Event& e) {
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
		SDL_Scancode key = e.key.keysym.scancode;

		if (key == SDL_SCANCODE_W || key == SDL_SCANCODE_A || key == SDL_SCANCODE_S || key == SDL_SCANCODE_D) {

			if (std::find(keyStack.begin(), keyStack.end(), key) == keyStack.end()) {
				keyStack.push_back(key);
			}
		}
	}
	else if (e.type == SDL_KEYUP) {
		SDL_Scancode key = e.key.keysym.scancode;

		// Remove key from stack
		keyStack.erase(std::remove(keyStack.begin(), keyStack.end(), key), keyStack.end());
	}

	// Update direction based on the most recent key
	if (!keyStack.empty()) {
		switch (keyStack.back()) {
		case SDL_SCANCODE_W: dir = UP; break;
		case SDL_SCANCODE_S: dir = DOWN; break;
		case SDL_SCANCODE_A: dir = LEFT; break;
		case SDL_SCANCODE_D: dir = RIGHT; break;
		default: dir = NONE; break;
		}
	}
	else {
		dir = NONE;
	}
}

void Player::fireSpell(Direction dir) {

	
}
