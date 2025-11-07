#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <SDL.h>
#include "player.hpp"
#include "gamearea.hpp"
#include "controller.hpp"

class Game {
public:

	SDL_Renderer* renderer;
	SDL_Window* mainScreen;

	void initSDL();
	void gameloop();
	void close();

private:
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	
};

#endif
