#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include <SDL.h>
#include <string>

SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer);

#endif
