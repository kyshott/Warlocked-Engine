#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include <vector>
#include "entity.hpp"

class Player : public Entity {
public:

    //A stack that stores key presses and pops as keys are released ... pretty novel I guess???? (definitely done before im not that cracked)
    std::vector<SDL_Scancode> keyStack;

    Player(int x, int y, int w, int h, SDL_Renderer* renderer, std::string givenpath, bool animated) : Entity(x, y, w, h, renderer, givenpath, animated) {};
    void handleEvent(const SDL_Event& e);
};

#endif
