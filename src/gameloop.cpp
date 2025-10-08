#include "headers/gameloop.hpp"
#include "headers/player.hpp"

//Initialize SDL and create a window and renderer
void Game::initSDL() {
	SDL_Init(SDL_INIT_EVERYTHING);

	SCREEN_WIDTH = 1000;
	SCREEN_HEIGHT = 1000;

	mainScreen = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(mainScreen, -1, 0);
}

//Close out SDL and any other SDL objects... add more later?
void Game::close() {
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(mainScreen);
	SDL_Quit();
}

void Game::initObjects() {
	Player player(500, 500, 48, 48, renderer, "resources/Player/Warlock.PNG", true, 400.0f, DOWN);

	Player player2(250, 250, 48, 48, renderer, "resources/Player/Warlock.PNG", true, 400.0f, DOWN);

	controllables.push_back(player);
	controllables.push_back(player2);
}

//Main game loop - basically is the "tick" of the game
void Game::gameloop() {

	initSDL();

	initObjects();

	bool quit = false;

	SDL_Event e;

	Uint32 lastTick = SDL_GetTicks();

	//While application is running - everything in this while loop is the "tick" or "loop"
	while (!quit)
	{
		Uint32 frameStart = SDL_GetTicks();
		Uint32 currentTick = SDL_GetTicks();
        float deltaTime = (currentTick - lastTick) / 1000.0f; // seconds
        lastTick = currentTick;

		if (deltaTime > 0.1f) deltaTime = 0.1f;

		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			//Handle input for all controllable objects
			for (auto& obj : controllables) {
				obj.handleEvent(e);
			}

		}
		//Clears the screen of last seen sprites after delay, which ultimately creates the "framerate" effect
		SDL_RenderClear(renderer);

		for (auto& obj : controllables) {
			obj.update(renderer, deltaTime);
		}
		//player.updateTexture(renderer);

		SDL_RenderPresent(renderer);

		// FPS cap at ~60 fps - 1000 / desired fps for calc
		Uint32 frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < 16) {
            SDL_Delay(16 - frameTime);
        }

	}

	close();
}