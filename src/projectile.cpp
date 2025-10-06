#include "headers/projectile.hpp"
#include "headers/textureloader.hpp"
#include <iostream>
#include <stdlib.h>
#include <algorithm>

// Fireball implementation

void FireBall::spawn(int x, int y, SDL_Renderer* renderer, Direction dir) {

    // x and y coordinates called relative to the player position/direction. Add (w * h +- 2 pixels to position)
    // based on directon enumeration
    body = Entity(x, y, 48, 48, renderer, texturePath, true);

    body.dir = dir;

}

void FireBall::contact() {

    

}

