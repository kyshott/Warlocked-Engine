#ifndef GAME_AREA_H
#define GAME_AREA_H

#include <SDL.h>
#include <vector>
#include "entity.hpp"
#include "memory"
#include <tinytmx.hpp>
#include "textureloader.hpp"
#include "player.hpp"

/**
 * @brief Class for managing a game area or "screen".
 * 
 * Manages the loading, rendering, and updating of a game area based on a tilemap file. Handles entity management, player reference, and area state saving/loading.
 * A GameArea object contains all information regarding what is currently drawn on and is interactable on screen. Each area is loaded from a tilemap file and contains its own entities
 * which are saved and loaded as the area is saved and loaded. This class is crucial to memory management and ensuring that resources are freed from memory when not being used.
 * 
 * @param mapFile Path to the tilemap file.
 * @param renderer SDL_Renderer for rendering.
 * @param ref Pointer to the player object.
 */
class GameArea {
public:

    // TODO: Come up with logic for freeing entities and objects that take up memory in each area
    // Use smart pointers for automatic memory management. Entities go into smart pointer vectors, areas go into smart pointer vectors, etc etc

    // Tileset texture for rendering map. Parsed from tilemap file.
    SDL_Texture* tileTex;

    // Map texture that contains all rendered layers of the tilemap for efficient rendering and avoidance of per-tile rendering each frame.
    SDL_Texture* mapTexture;

    // Unique pointer to the tinytmx map object.
    std::unique_ptr<tinytmx::Map> map;

    // Unique pointer vector containing all entities present in the game area. 
    std::vector<std::unique_ptr<Entity>> entities;

    // Vector containing all controllable entities in the area. May be deprecated later.
    std::vector<Player> controllables;

    /**
     * @brief Constructor for GameArea class.
     * 
     * Initializes a GameArea object by loading the specified tilemap file, rendering the map layers to a texture, and setting up the player reference.
     * 
     * @param mapFile Path to the tilemap file.
     * @param renderer SDL_Renderer for rendering.
     * @param ref Pointer to the player object.
     */
    GameArea(std::string mapFile, SDL_Renderer* renderer, Player* ref);

    /**
     * @brief Saves the current state of the area.
     * 
     * Saves the state of the area, including entity positions and other relevant data, to a file for later retrieval. Called when transitioning out of the area
     * and ultimately frees all associated memory.
     */
    void saveState();

    /**
     * @brief Loads the saved state of the area. 
     * 
     * Loads the saved state of the area. Always called when entering (and thus, instantiating) the area. Loads entity positions and other relevant data from a previously saved file.
     */
    void loadState();

    /**
     * @brief Add entity to the entity vector.
     * 
     * Adds the specified entity to the entities unique pointer vector. Helper method.
     * 
     * @param e Entity object to be added.
     */
    void addEntity(Entity e);

    /**
     * @brief Updates the game area.
     * 
     * Method to update the game area. Called within the main game loop to handle rendering and updating of the area and its entities, including the player. Handles calls for
     * AABB entity collision detection as well as entity updates for position and sprite rendering.
     * 
     * @param dt Delta time.
     * @param renderer SDL_Renderer for rendering.
     */
    void areaUpdate(float dt, SDL_Renderer* renderer);

    /**
     * @brief Renders the layers of the map from the tilemap data and stores them accordingly.
     * 
     * Conventionally, tiles on layer 0 are non-colliding and are therefore appended to the background texture, and tiles on layer 1 are colliding and are appended to the entities vector.
     * This method handles the rendering of the map layers to the map texture for efficient rendering during the game loop. Will most likely be deprecated later to be replaced with the tilemaptools function.
     * 
     * @param map Pointer to the tinytmx::Map object.
     * @param tileTex SDL_Texture for the tileset.
     * @param tileset Pointer to the tinytmx::Tileset object.
     * @param renderer SDL_Renderer for rendering.
     */
    void layerRender(tinytmx::Map* map, SDL_Texture* tileTex, const tinytmx::Tileset* tileset, SDL_Renderer* renderer);

private:

    // Reference to the player object within the area.
    Player* player;

};


#endif
