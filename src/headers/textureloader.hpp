#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include <SDL.h>
#include <string>

/**
 * @brief Creates an SDL texture out of a provided image.
 * 
 * Takes a path to a given image file (PNG preferred) and creates an SDL texture. Returns a pointer to the SDL texture. Very useful for any cases where a texture is loaded.
 * Frees all unused utilities after the texture is loaded, including the used SDL_Surface to draw the image to a texture.
 * 
 * @param path Path to the image file to be converted to a texture.
 * @param renderer SDL_Renderer for rendering.
 * 
 * @returns SDL_Texture object made from image.
 */
SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer);

#endif
