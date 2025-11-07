#include "headers/gameloop.hpp"
#include "headers/player.hpp"
#include <memory>
#include "headers/gamearea.hpp"
#include "headers/controller.hpp"

//Initialize SDL and create a window and renderer
void Game::initSDL() {
	SDL_Init(SDL_INIT_EVERYTHING);

	SCREEN_WIDTH = 1000;
	SCREEN_HEIGHT = 1000;

	mainScreen = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(mainScreen, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); // Use vsync
}

//Close out SDL and any other SDL objects... add more later?
void Game::close() {
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(mainScreen);
	SDL_Quit();
}

//Main game loop - basically is the "tick" of the game
void Game::gameloop() {

	initSDL();

	Player player(500, 500, 48, 48, renderer, "resources/Player/Warlock.PNG", true, 75.0f, DOWN);

	GameArea gameArea("resources/Maps/testmap.tmx", renderer, &player);

	Controller controller(&player);

	bool quit = false;

	SDL_Event e;

	Uint32 lastTick = SDL_GetTicks();

	//While application is running - everything in this while loop is the "tick" or "loop"
	while (controller.quit == false) {
		Uint64 now = SDL_GetPerformanceCounter();
		float deltaTime = (now - lastTick) / (float)SDL_GetPerformanceFrequency();
		lastTick = now;

		if (deltaTime > 0.1f) deltaTime = 0.1f;

		// Accept user input
		controller.input(deltaTime, e);

		//Clears the screen of last seen sprites after delay, which ultimately creates the "framerate" effect
		SDL_RenderClear(renderer);

		gameArea.areaUpdate(deltaTime, renderer);

		SDL_RenderPresent(renderer);

		// FPS cap at ~60 fps - 1000 / desired fps for calc
		//Uint32 frameTime = SDL_GetTicks() - frameStart;
		/*
        if (frameTime < 16) {
            SDL_Delay(16 - frameTime);
        }
			*/

	}

	close();
}