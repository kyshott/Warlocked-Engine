#include "headers/gameloop.hpp"
#include "headers/player.hpp"
#include <memory>
#include "headers/gamearea.hpp"
#include "headers/controller.hpp"

Game::Game() {
	SCREEN_WIDTH = 1000;
	SCREEN_HEIGHT = 1000;

	initSDL();
}

//Initialize SDL and create a window and renderer
void Game::initSDL() {
	SDL_Init(SDL_INIT_EVERYTHING);

	mainScreen = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(mainScreen, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); // Use vsync. Implement toggle to turn this on/off.
}

void Game::close() {
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(mainScreen);
	SDL_Quit();
}

void Game::gameloop() {

	Player player(500, 500, 48, 48, renderer, "assets/Player/Warlock.PNG", true, 75.0f, DOWN);

	GameArea gameArea("assets/Maps/testmap.tmx", renderer, &player);

	Controller controller(&player);

	bool quit = false;

	Uint32 lastTick = SDL_GetTicks();

	//Zero initialize the event structure
	SDL_Event e{};

	//While application is running - everything in this while loop is the "tick" or "loop"
	while (controller.quit == false) {

		Uint64 now = SDL_GetPerformanceCounter();
		float deltaTime = (now - lastTick) / (float)SDL_GetPerformanceFrequency(); // Type cast to allow for per-device delta time
		lastTick = now;

		if (deltaTime > 0.1f) deltaTime = 0.1f;

		// Accept user input
		controller.input(deltaTime, e);

		//Clears the screen of last seen sprites after delay, which ultimately creates the "framerate" effect
		SDL_RenderClear(renderer);

		gameArea.areaUpdate(deltaTime, renderer);

		SDL_RenderPresent(renderer);

	}

	gameArea.saveState();
	close();
}