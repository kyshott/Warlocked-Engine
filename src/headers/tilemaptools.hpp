#ifndef TILEMAP_TOOLS_H
#define TILEMAP_TOOLS_H

#include <SDL.h>
#include <tinytmx.hpp>
#include <memory>
#include "entity.hpp"

/**
 * @brief Creates a map texture given a tmx map.
 * 
 * Creates a map texture given a tinytmx map object. The map, by itself, is simply a texture and must be rendered properly in order to function properly.
 * The map texture by itself must be rendered after creation, which is done in another method.
 * 
 * @param renderer SDL_Renderer used for rendering.
 * @param map Unique pointer to tinytmx map object.
 * 
 * @returns SDL_Texture object containing the parsed map data.
 */
SDL_Texture* createMapTexture(SDL_Renderer* renderer, std::unique_ptr<tinytmx::Map> map);

void renderMap(SDL_Renderer* renderer, SDL_Texture* mapTexture);

/**
* @brief Renders and initializes entities based on a tilemap layer designated for entity spawns.
*
* Do initial rendering for entities then return the vector for entities. Entities are to be included on a specific tilemap layer which informs the 
* GameArea that these specific tiles are entities and are not part of the background texture. This function is not responsible for updating the entities relative
* to delta time, just for initial rendering and placement based on the parsed tilemap file.
*
* @param renderer The SDL_Renderer used for rendering the entities.
* @return A vector of Entity objects that have been rendered and initialized.
*/
std::vector<Entity> renderSpawnEntities(SDL_Renderer* renderer);

#endif