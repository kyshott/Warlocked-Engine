#ifndef TILEMAP_TOOLS_H
#define TILEMAP_TOOLS_H

#include <SDL.h>
#include <tinytmx.hpp>
#include <memory>
#include "entity.hpp"

/**
 * @brief Creates a map texture given a tmx map.
 * 
 * Initializes a map texture given a tinytmx map object. The map, by itself, is simply a texture object and does not have any data.
 * This simply prepares an SDL_Texture object to be rendered to based on the dimension specifications retrieved from a parsed map object.
 * 
 * @param renderer SDL_Renderer used for rendering.
 * @param map Pointer to tinytmx map object.
 * 
 * @return SDL_Texture* object containing the parsed map data.
 */
SDL_Texture* initMapTexture(SDL_Renderer* renderer, tinytmx::Map* map);

/**
 * @brief Creates a tileset texture based on a tinytmx map object.
 * 
 * Generates a designated texture for the provided tinytmx map's tileset. By itself, the tileset texture is quite useless without information of where the
 * tileset textures are rendered and their ID. Ultimately a helper method that really shouldn't be called without being used as part of the map rendering pipeline.
 * Currently assumes only one tileset per map, which is not always true (will be updated later to reflect this).
 * 
 * @param renderer SDL_Renderer used for rendering.
 * @param map Pointer to tinytmx map object.
 * 
 * @return SDL_Texture* object containing the parsed tilset data.
 */
SDL_Texture* createTileSetTexture(SDL_Renderer* renderer, tinytmx::Map* map);

/**
 * @brief Creates a complete tinytmx map texture for layer 0.
 * 
 * Generates a complete tinytmx map texture to be used for rendering. Sets the rendering target to the mapTexture parameter then uses the data from the 
 * parsed map object along with the tileset texture to draw each tile in its respective position. Currently, assumes all general tiles are on layer 0 and not on any others.
 * Once rendering is complete, clears the render target and returns the complete map texture for layer 0.
 * 
 * @param map The parsed tinytmx map.
 * @param tileTex The map tileset texture.
 * @param mapTexture The map texture target - generally just a defined shape.
 * @param tileset The map tileset object, retrieved from the parsed map.
 * @param renderer SDL_Renderer used for rendering.
 * 
 * @return The completed layer 0 tinytmx map texture.
 */
SDL_Texture* renderMap(tinytmx::Map* map, SDL_Texture* tileTex, SDL_Texture* mapTexture, const tinytmx::Tileset* tileset, SDL_Renderer* renderer);

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