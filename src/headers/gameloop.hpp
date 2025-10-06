#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <SDL.h>
#include "player.hpp"

class Game {
public:
	
	//BEHOLD! THE GAME TICK!
	double delta;
	//BEHOLD! THE GAME TICK!

	Uint32 NOW, LAST;

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
