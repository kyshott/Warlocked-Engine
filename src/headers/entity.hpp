#ifndef ENTITY_H
#define ENTITY_H

#include <SDL.h>
#include <string>
#include <memory>
#include <vector>

// Direction enumeration for entity movement and orientation.
// Available values: NONE, UP, DOWN, LEFT, RIGHT.
enum Direction { NONE, UP, DOWN, LEFT, RIGHT };

// Unused struct for potential future use with entity positioning.
struct Position {
    float x;
    float y;
    int layer; // For future use with multiple layers... don't know if this will ever be used, but may be useful for engine purposes and parallaxing if that ever becomes a thing
};

/**
 * @brief Base class for all colliding objects.
 * 
 * Can be used by itself for simple colliding objects, but it is recommended to extend this class for more complex entities with unique behaviors. Contains all general logic
 * for collision, positional updates, and sprite rendering/management relative to the supplied delta time.
 * 
 * Takes a number of positional arguments in its constructor for instantiation all related to sprite rendering, positional/directional updates, movement speed (if applicable) and collision detection.
 * 
 * @param x Initial x position.
 * @param y Initial y position.
 * @param w Width of the entity.
 * @param h Height of the entity.
 * @param renderer SDL_Renderer for rendering.
 * @param givenpath File path to the entity's sprite texture.
 * @param animated Boolean indicating if the entity is animated.
 * @param spd Speed of the entity.
 * @param _dir Initial direction of the entity. If NONE, entity will be invisible until direction is changed.
 */
class Entity {
public:

    // Directional state of the entity.
    Direction dir;

    // Sprite width.
    int spriteWidth;

    // Sprite height.
    int spriteHeight;

    // Current index of sprite based on sprite sheet.
    int spriteindex;

    // Entity movement speed, if applicable.
    float speed;

    // Entity X coordinate position.
    float posX;

    // Entity Y coordinate position.
    float posY;

    // Entity collision rectangle.
    SDL_Rect rect;

    // Entity source rectangle for sprite sheet rendering.
    SDL_Rect srcRect;

    // Path to the entity's sprite texture.
    std::string path;

    // Entity texture.
    SDL_Texture* texture;

    // Flag to indicate whether animation applies to sprite.
    bool isAnimated;

    // Flag to indicate whether entity is currently colliding with another entity.
    bool contacting;

    /**
     * @brief Constructor for the Entity class.
     * 
     * Initializes an Entity object with specified position, size, texture path, animation status, speed, and direction. Acts as the basis for all colliding objects. 
     * 
     * @param x Initial x position.
     * @param y Initial y position.
     * @param w Width of the entity.
     * @param h Height of the entity.
     * @param renderer SDL_Renderer for rendering.
     * @param givenpath File path to the entity's sprite texture.
     * @param animated Boolean indicating if the entity is animated.
     * @param spd Speed of the entity.
     * @param _dir Initial direction of the entity. If NONE, entity will be invisible until direction is changed.
     */
    Entity(int x, int y, int w, int h, SDL_Renderer* renderer, std::string givenpath, bool animated, float spd, Direction _dir);

    /**
     * @brief Renders the entity's sprite to the screen.
     * 
     * Renders the entity's sprite at its current position using the provided SDL_Renderer. Ultimately used as a helper function within the update method.
     * 
     * @param renderer SDL_Renderer for rendering.
     */
    void renderSprite(SDL_Renderer* renderer);

    /**
     * @brief Update entity position and state.
     * 
     * Updates the entity's position based on its speed, direction and delta time. Handles directional sprite transitions rendering.
     * 
     * @param renderer SDL_Renderer for rendering.
     * @param dt Delta time.
     */
    void update(SDL_Renderer* renderer, float dt);

    /**
     * @brief Initializes the entity's texture.
     * 
     * Initializes the entity's texture from the specfied file path using the provided renderer. Consequentially stores the sprite within the entity's "texture" attribute
     * to be used for animation, rendering, etc. Uses the textureloader utility for loading the texture.
     * 
     * @param renderer SDL_Renderer for rendering.
     */
    void initTexture(SDL_Renderer* renderer);


    bool collider(double dt, const std::vector<std::unique_ptr<Entity>>& others);

    /**
     * @brief Handles border collision and boundary correction.
     * 
     * Ensures the entity remains within the defined level boundaries. Clamps the entity to the boundaries and prevents it from moving outside the level area. 
     * Not entirely necessary if collision detection within level boundaries is implemented via tilemap, but useful as a backup.
     * 
     * @param levelWidth Width of the level.
     * @param levelHeight Height of the level.  
     * @param override If true, "disables" border collision. 
     */
    void borderCollision(int levelWidth, int levelHeight, bool override);

};

#endif