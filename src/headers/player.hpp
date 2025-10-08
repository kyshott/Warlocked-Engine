#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include <vector>
#include "entity.hpp"

enum PlayerState {IDLE, MOVING, FIRING}; // For Player state machine

class Player : public Entity {
public:

    //A stack that stores key presses and pops as keys are released ... pretty novel I guess???? (definitely done before im not that cracked)
    std::vector<SDL_Scancode> keyStack;

    Player(int x, int y, int w, int h, SDL_Renderer* renderer, std::string givenpath, bool animated, float spd, Direction _dir) : Entity(x, y, w, h, renderer, givenpath, animated, spd, _dir) {};
    void handleEvent(const SDL_Event& e);
    void fireSpell(Direction dir);
};

#endif
