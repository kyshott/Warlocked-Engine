#include "headers/textureloader.hpp"
#include <SDL_image.h>

//Loads image file, converts to a surface, passes into texture, then frees surface and returns texture
SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer) {
	
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	SDL_Texture* newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);

	return newTexture;
}