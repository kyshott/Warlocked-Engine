#include "headers/entity.hpp"
#include "headers/textureloader.hpp"
#include <iostream>
#include <filesystem>

Entity::Entity(int x, int y, int w, int h, SDL_Renderer* renderer, std::string givenpath, bool animated, float spd, Direction _dir) {

	contacting = false; // AABB collision

	this->speed = spd;

	isAnimated = animated;
	
	spriteWidth = w;
	spriteHeight = h;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = spriteWidth;
	srcRect.h = spriteHeight;

	path = givenpath;

	posX = x;
	posY = y;
	
	rect = { x, y, spriteWidth, spriteHeight };
	this->dir = _dir;
	initTexture(renderer);
}

void Entity::update(SDL_Renderer* renderer, float dt) {

	//std::cout << "Speed: " << speed << " dt: " << dt << " dir: " << dir << " rect.x: " << rect.x << " rect.y: " << rect.y << std::endl;

	if(!isAnimated) {
        switch (dir)
        {
        case DOWN:
            posY += speed * dt; spriteindex = 0; break;
        case UP:
            posY -= speed * dt; spriteindex = 10; break;
        case LEFT:
            posX -= speed * dt; spriteindex = 7; break;
        case RIGHT:
            posX += speed * dt; spriteindex = 4; break;
        case NONE:
            break;
        }
    }
    if(isAnimated) {
        switch (dir)
        {
        case DOWN:
            posY += speed * dt; spriteindex = 0; break;
        case UP:
            posY -= speed * dt; spriteindex = 10; break;
        case LEFT:
            posX -= speed * dt; spriteindex = 7; break;
        case RIGHT:
            posX += speed * dt; spriteindex = 4; break;
        case NONE:
            break;
        }
    }

	// Window border clamping - temporary until AABB is fully implemented
	// Maybe keep as a feature? Add separate objects for transporting player to other areas? Keep as a failsafe for clipping with area walls?
	borderCollision(1000, 1000, false);

    rect.x = static_cast<int>(posX);
    rect.y = static_cast<int>(posY);

    renderSprite(renderer);
}

bool Entity::collider(double dt, const std::vector<std::unique_ptr<Entity>>& others) {
	// Find way to dereference unique pointer from vector so rect can be accessed

	return true;
}

void Entity::borderCollision(int levelWidth, int levelHeight, bool override) {
	
	if(override) return;
	if (posX < 0) posX = 0;
    if (posY < 0) posY = 0;
    if (posX + 50 > levelWidth) posX = levelWidth - 50;
    if (posY + 50 > levelHeight) posY = levelHeight - 50;

}

void Entity::renderSprite(SDL_Renderer* renderer) {
	
	srcRect.x = spriteindex * spriteWidth;
	
	SDL_RenderCopy(renderer, texture, &srcRect, &rect);
}

void Entity::initTexture(SDL_Renderer* renderer) {

	std::cout << "Rendering from path: " << path << std::endl;

	texture = loadTexture(path, renderer);

	if (texture == NULL) {
		std::cerr << "Texture failed to load. SDL_Error: " << SDL_GetError() << std::endl;
	}
}