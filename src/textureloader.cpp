#include "headers/textureloader.hpp"
#include <SDL_image.h>
#include <iostream>

//Loads image file, converts to a surface, passes into texture, then frees surface and returns texture
SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer) {
	
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	if (!loadedSurface) {
    	std::cerr << "IMG_Load failed for " << path << ": " << IMG_GetError() << std::endl;
	}

	SDL_Texture* newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

	if (!newTexture) {
		std::cerr << "SDL_CreateTextureFromSurface failed: " << SDL_GetError() << std::endl;
	}

	SDL_FreeSurface(loadedSurface);

	return newTexture;
}