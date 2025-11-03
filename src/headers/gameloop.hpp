#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <SDL.h>
#include "player.hpp"
#include "gamearea.hpp"

class Game {
public:

	std::vector<Player> controllables;

	SDL_Renderer* renderer;
	SDL_Window* mainScreen;

	void initSDL();
	void gameloop();
	void close();
	void initObjects();

private:
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	
};

#endif
