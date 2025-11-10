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

    //A stack that stores key presses and pops as keys are released ... pretty novel I guess???? (definitely done before im not that cracked)
    std::vector<SDL_Scancode> keyStack;

    Player(int x, int y, int w, int h, SDL_Renderer* renderer, std::string givenpath, bool animated, float spd, Direction _dir) : Entity(x, y, w, h, renderer, givenpath, animated, spd, _dir) {};
    void handleMoveEvent(const SDL_Event& e);
    void fireSpell(Direction dir);
};

#endif
