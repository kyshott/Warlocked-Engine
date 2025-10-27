#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SDL.h>
#include "entity.hpp"

class FireBall : public Entity {
public:

	// Connect particle system somehow once it is implemented

	void spawn(int x, int y, SDL_Renderer* renderer, Direction dir, float speed);
	void contact();

	Entity body; // Main "body" of the fireball with all inherited methods

private:

	std::string texturePath = "resources/Player/Warlock.PNG";

};

#endif
