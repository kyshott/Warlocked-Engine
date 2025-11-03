#include "headers/gamearea.hpp"
#include "memory"
#include "headers/textureloader.hpp"
#include <tinytmx.hpp>
#include <iostream>

GameArea::GameArea(int idk) {
    return;
}

void GameArea::initMap(std::string mapFile, SDL_Renderer* renderer) {
    // Initialize the game area, load map data, etc... loaded from file
    // Render map layers, initialize entities, etc
    // Iterate through all entities stored in the area from loadState and initialize them 

    // Create smart pointer for map
    std::unique_ptr<tinytmx::Map> map = std::make_unique<tinytmx::Map>();
    map->ParseFile(mapFile);

    // Get tileset, image, then path to use for SDL rendering.
    const tinytmx::Tileset* set = map->GetTileset(0); // Assuming only one tileset per area...
    const tinytmx::Image* image = set->GetImage();
    const std::string tilepath = image->GetSource();

    std::cout << "Map loaded: " << mapFile << std::endl;
    std::cout << "Layers: " << map->GetNumLayers() << std::endl;
    std::cout << "Tilesets: " << map->GetNumTilesets() << std::endl;

    SDL_Texture* tileTex = loadTexture(tilepath, renderer);

    int w, h;
    SDL_QueryTexture(tileTex, nullptr, nullptr, &w, &h);
    std::cout << "Tileset texture size: " << w << "x" << h << std::endl;

    layerRender(map.get(), tileTex, set, renderer);

    //loadState();
}

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

// Updates everything in the game area, including entity positions, rendering, collision etc
void GameArea::areaUpdate(float dt, SDL_Renderer* renderer) {

    for (auto& entity : entities) {
        entity->update(renderer, dt);
        entity->collider(dt, entities);
    }
   
}

