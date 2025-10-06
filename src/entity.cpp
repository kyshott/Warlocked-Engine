#include "headers/entity.hpp"
#include "headers/textureloader.hpp"
#include <iostream>
#include <filesystem>

//Define player rectangle starting position and width/height - update path to the sprite sheet
Entity::Entity(int x, int y, int w, int h, SDL_Renderer* renderer, std::string givenpath, bool animated) {

	contacting = false; // AABB collision

	isAnimated = animated;
	
	spriteWidth = w;
	spriteHeight = h;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = spriteWidth;
	srcRect.h = spriteHeight;

	path = givenpath;
	rect = { x, y, spriteWidth, spriteHeight };
	dir = DOWN;
	initTexture(renderer);
}

//Update player position based on key held
void Entity::update(SDL_Renderer* renderer) {

	renderSprite(renderer);

	//Window boundary detection... 100% temporary in this case will be changed later
	if (rect.x < 0) rect.x = 0;
	if (rect.y < 0) rect.y = 0;
	if (rect.x + 50 > 1000) rect.x = 1000 - 50;
	if (rect.y + 50 > 1000) rect.y = 1000 - 50;

	if(!isAnimated) {
		switch (dir)
		{
		case DOWN:
			rect.y += 10; spriteindex = 0; break;
		case UP:
			rect.y -= 10; spriteindex = 10; break;
		case LEFT:
			rect.x -= 10; spriteindex = 7; break;
		case RIGHT:
			rect.x += 10; spriteindex = 4; break;
		case NONE:
			break;
		}
	}
	//TODO: Implement delta time system to allow for sprite animation...
	if(isAnimated) {
		switch (dir)
		{
		case DOWN:
			rect.y += 10; spriteindex = 0; break;
		case UP:
			rect.y -= 10; spriteindex = 10; break;
		case LEFT:
			rect.x -= 10; spriteindex = 7; break;
		case RIGHT:
			rect.x += 10; spriteindex = 4; break;
		case NONE:
			break;
		}
	}
}

bool Entity::collider(const Entity& check) const {

	return SDL_HasIntersection(&rect, &check.rect);
	
}


//Render / update sprite of entity based on position
void Entity::renderSprite(SDL_Renderer* renderer) {
	
	srcRect.x = spriteindex * spriteWidth;
	
	SDL_RenderCopy(renderer, texture, &srcRect, &rect);
}

//Initializes the texture or "sprite sheet" for the entity
void Entity::initTexture(SDL_Renderer* renderer) {

	std::cout << "Rendering from path: " << path << std::endl;

	texture = loadTexture(path, renderer);

	if (texture == NULL) {
		std::cerr << "Texture failed to load. SDL_Error: " << SDL_GetError() << std::endl;
	}
}