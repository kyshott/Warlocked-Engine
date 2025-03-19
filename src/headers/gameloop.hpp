#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <SDL.h>
#include "player.hpp"

class Game {
public:
	SDL_Renderer* renderer;
	SDL_Window* mainScreen;

	void initSDL();
	void gameloop();
	void close();

private:
	const int SCREEN_WIDTH = 1000;
	const int SCREEN_HEIGHT = 1000;
	
};

#endif
