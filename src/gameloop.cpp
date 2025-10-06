#include "headers/gameloop.hpp"
#include "headers/player.hpp"

//Initialize SDL and create a window and renderer
void Game::initSDL() {
	SDL_Init(SDL_INIT_EVERYTHING);

	mainScreen = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(mainScreen, -1, 0);
}

//Close out SDL and any other SDL objects... add more later?
void Game::close() {
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(mainScreen);
	SDL_Quit();
}

//Main game loop - basically is the "tick" of the game
void Game::gameloop() {

	SCREEN_WIDTH = 1000;
	SCREEN_HEIGHT = 1000;

	initSDL();

	Player player(500, 500, 48, 48, renderer, "resources/Player/Warlock.PNG", true);

	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	//While application is running
	while (!quit)
	{
		//CRUCIAL - the ultimate delta calculation....

		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			player.handleEvent(e);

		}
		//Clears the screen of last seen sprites after delay, which ultimately creates the "framerate" effect
		SDL_RenderClear(renderer);

		player.update(renderer);
		//player.updateTexture(renderer);

		//Render everything
		SDL_RenderPresent(renderer);

		//Set fps
		SDL_Delay(16);

	}

	close();
}