#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "entity.hpp"

class FireBall : public Entity {
public:
	void spawn();
	void contact();

private:
	int spawnLocation;

	const int WIDTH = 50;
	const int HEIGHT = 50;
};

#endif
