#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include <vector>
#include "entity.hpp"

// Player state machine enumeration. Similar to the directional enumeration, contains
// all possible states the player may be in. Available states: IDLE, MOVING, FIRING.
enum PlayerState {IDLE, MOVING, FIRING};

/**
 * @brief The player class.
 * 
 * Extends the Entity class to create a controllable Entity. Is able to take in processed inputs from the controller class to change its state,
 * direction, position, etc.
 * 
 */
class Player : public Entity {
public:

    //A stack that stores key presses and pops as keys are released (a la NES D-pad, where only one direction press is possible at a time due to the controller's design).
    std::vector<SDL_Scancode> keyStack;

    /**
     * @brief Constructor for Player class.
     * @overload Entity constructor.
     * 
     * Overloads the base entity constructor to account for extra parameters needed for player instantiation. Otherwise, most attribute assignments are the same and are 
     * functionally identical to that of the base class. General use is the exact same - the player entity is instantiated at the given coordinates. Useful for saving/loading in a 
     * specific position relative to the Game Area.
     * 
     * @param x Initial x position.
     * @param y Initial y position.
     * @param w Width of the entity.
     * @param h Height of the entity.
     * @param renderer SDL_Renderer for rendering.
     * @param givenpath File path to the player's sprite texture.
     * @param animated Boolean indicating if the player is animated. Generally, this will be set to true for a player character.
     * @param spd Speed of the entity.
     * @param _dir Initial direction of the player. If NONE, player will be invisible until direction is changed.
     */
    Player(int x, int y, int w, int h, SDL_Renderer* renderer, std::string givenpath, bool animated, float spd, Direction _dir) : Entity(x, y, w, h, renderer, givenpath, animated, spd, _dir) {};

    /**
     * @brief Handles a movement input event.
     * 
     * Using the controller class and keyStack vector, changes the player direction and sets player velocity in the direction of the registered input at the top of the keyStack vector.
     * 
     * @param e The SDL event to handle.
     */
    void handleMoveEvent(const SDL_Event& e);

    /**
     * @brief Fire a projectile in the player direction.
     * 
     * Shoots a projectile at a given velocity based on the player's direction.
     * Not implemented at the moment, may be deprecated later.
     * 
     * @param dir Direction to fire projectile.
     */
    void fireSpell(Direction dir);
};

#endif
