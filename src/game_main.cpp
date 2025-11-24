#include <SDL.h>
#include "headers/gameloop.hpp"
#include <iostream>
#include <filesystem>
#undef main

int main() {

	//Debug statement for checking working dir for assets
	std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

	Game game;

	game.gameloop();

	return 0;

}