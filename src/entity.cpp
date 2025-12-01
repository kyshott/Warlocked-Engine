#include "headers/entity.hpp"
#include "headers/textureloader.hpp"
#include <iostream>
#include <filesystem>
#include <vector>

uint64_t hashKey(int x, int y) {
    return (uint64_t)x << 32 | (uint32_t)y;
}

int toCellCoord(float pos) {
    return (int)std::floor(pos / cellSize);
}

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

    // Call some sort of sprite loop function in each switch case before break... hopefully trivial?
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

	//std::cout << "Rendering from path: " << path << std::endl;

	texture = loadTexture(path, renderer);

	if (texture == NULL) {
		std::cerr << "Texture failed to load. SDL_Error: " << SDL_GetError() << std::endl;
	}
}

bool Entity::narrowPhase(const SDL_Rect& a, const SDL_Rect& b) {
    return (
        a.x < b.x + b.w &&
        a.x + a.w > b.x &&
        a.y < b.y + b.h &&
        a.y + a.h > b.y
        );
}

std::vector<Entity*> Entity::broadPhase() {
	// Placeholder broad-phase collision detection
	// In a real implementation, this would return a list of potential colliders based on spatial partitioning or other methods
	return std::vector<Entity*>();
}

void Entity::finalCollision() {

    std::vector<Entity*> candidates = broadPhase();

    for (auto& collider : candidates) {
        if (narrowPhase(rect, collider.rect)) {
            // Moving right
            if (dir == RIGHT) {
                posX = collider.x - rect.w;
            }
            // Moving left
            else if (dir == LEFT) {
                posX = collider.x + collider.w;
            }
            else if (dir == UP) {
				posY = collider.y + collider.h;
            }
            else if (dir == DOWN) {
                posY = collider.y - rect.h;
            }
        }
    }
}