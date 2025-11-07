#include "headers/gamearea.hpp"
#include "memory"
#include "headers/player.hpp"
#include "headers/textureloader.hpp"
#include <tinytmx.hpp>
#include <iostream>

GameArea::GameArea(std::string mapFile, SDL_Renderer* renderer, Player* ref) {
    // Initialize the game area, load map data, etc... loaded from file
    // Render map layers, initialize entities, etc
    // Iterate through all entities stored in the area from loadState and initialize them 

    player = ref;

    map = std::make_unique<tinytmx::Map>();
    map->ParseFile(mapFile);

    int mapPixelW = map->GetWidth() * map->GetTileWidth();
    int mapPixelH = map->GetHeight() * map->GetTileHeight();

    mapTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, mapPixelW, mapPixelH);

    // Get tileset, image, then path to use for SDL rendering.
    const tinytmx::Tileset* set = map->GetTileset(0); // Assuming only one tileset per area...
    const tinytmx::Image* image = set->GetImage();
    const std::string tilepath = image->GetSource();

    // Set render target to the map texture, render all layers to this texture then set render target back to default.
    // This should make rendering the map much more efficient as we only have to render one texture instead of multiple tiles each frame.
    SDL_SetRenderTarget(renderer, mapTexture);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    tileset = loadTexture(tilepath, renderer);
    layerRender(map.get(), tileset, map->GetTileset(0), renderer);

    SDL_SetRenderTarget(renderer, nullptr);

    //loadState();
}

// Delta time included as parameter here for future use with entity updates and animated tiles
void GameArea::areaUpdate(float dt, SDL_Renderer* renderer){

    SDL_RenderCopy(renderer, mapTexture, nullptr, nullptr);

    player->update(renderer, dt);

    for (auto& entity : entities) {
        entity->update(renderer, dt);
        entity->collider(dt, entities);
    }

    //layerRender(map.get(), tileset, map->GetTileset(0), renderer);
   
}

// Renders the layers of the map from the tilemap data and stores them accordingly. Conventionally, tiles on layer 0 are non-colliding and are therefore appended to the
// background texture, and tiles on layer 1 are colliding and are appended to the entities vector to allow for collision detection.
void GameArea::layerRender(tinytmx::Map* map, SDL_Texture* tileTex, const tinytmx::Tileset* tileset, SDL_Renderer* renderer) {
    for (int l = 0; l < map->GetNumLayers(); l++) {

    const tinytmx::Layer* layer = map->GetLayer(l); // Get layer... 0 for background (non colliding) 1 for foreground (colliding)

    if (!layer->IsVisible()) continue; // If layer is invisible, skip rendering
    
    int width = layer->GetWidth();
    int height = layer->GetHeight();
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int tileID = map->GetTileLayer(l)->GetDataTileFiniteMap()->GetTileGid(x, y); // Get tile ID from layer iteration
            if (tileID == 0) continue; // empty tile, skip
            
            int localID = tileID - tileset->GetFirstGid();
            
            int tilesetCols = tileset->GetColumns();
            int tileW = tileset->GetTileWidth();
            int tileH = tileset->GetTileHeight();
            
            // Calculate offsets for specific tile based on local ID
            SDL_Rect srcRect;
            srcRect.x = (localID % tilesetCols) * tileW;
            srcRect.y = (localID / tilesetCols) * tileH;
            srcRect.w = tileW;
            srcRect.h = tileH;
            
            SDL_Rect dstRect;
            dstRect.x = x * tileW;
            dstRect.y = y * tileH;
            dstRect.w = tileW;
            dstRect.h = tileH;

            // Get tileset texture index for tile, load texture based on index then render

            SDL_RenderCopy(renderer, tileTex, &srcRect, &dstRect);
        }
    }
}
}

void GameArea::saveState() {
    // Save the current state of the game area, entities, etc... to a file

    // Save entity positional and other instance data to something

    entities.clear(); // Free up memory for entities

    SDL_DestroyTexture(tileset);
    SDL_DestroyTexture(mapTexture);
}

void GameArea::loadState() {
    // Load the state of the game area that was previously loaded from saveState...
    
    // Load entity from data file (whatever it is)
    // Call addEntity() for each entity in this data file
}

// I can either pass a unique pointer as a parameter and add it to the vector, or pass a raw pointer and convert it to a unique pointer here... idk which is better
void GameArea::addEntity(Entity e) {

   entities.push_back(std::make_unique<Entity>(e));

}
