#ifndef ENTITY_H
#define ENTITY_H

#include <SDL.h>
#include <string>

enum Direction { NONE, UP, DOWN, LEFT, RIGHT };

struct Position {
    float x;
    float y;
    int layer; // For future use with multiple layers... don't know if this will ever be used, but may be useful for engine purposes and parallaxing if that ever becomes a thing
};

class Entity {
public:

    Direction dir;

    int spriteWidth;
    int spriteHeight;
    int spriteindex;

    float speed;
    float posX;
    float posY;

    SDL_Rect rect;
    SDL_Rect srcRect;

    std::string path;

    SDL_Texture* texture;

    bool isAnimated;

    bool contacting;

    Entity(int x, int y, int w, int h, SDL_Renderer* renderer, std::string givenpath, bool animated, float spd, Direction _dir);
    void renderSprite(SDL_Renderer* renderer);
    void update(SDL_Renderer* renderer, float dt);
    void initTexture(SDL_Renderer* renderer);
    bool collider(double dt, const std::vector<Entity*>& others);

};

#endif