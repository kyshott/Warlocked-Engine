#include "headers/tilemaptools.hpp"
#include "headers/textureloader.hpp"
#include <memory>
#include "tinytmx.hpp"
#include <iostream>

SDL_Texture* initMapTexture(SDL_Renderer* renderer, tinytmx::Map* map) {

    if (!renderer || !map) {
        std::cerr << "Renderer or map not allocated. Check your map file paths." << SDL_GetError() << std::endl;
        return nullptr;
    }

    int mapPixelW = map->GetWidth() * map->GetTileWidth();
    int mapPixelH = map->GetHeight() * map->GetTileHeight();

    SDL_Texture* mapTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, mapPixelW, mapPixelH); // Different from standard texture loading... Probably optional but it works

    return mapTexture;

}

SDL_Texture* createTileSetTexture(SDL_Renderer* renderer, tinytmx::Map* map) {

    if (!renderer || !map) {
        std::cerr << "Renderer or map not allocated. Check your map file paths." << SDL_GetError() << std::endl;
        return nullptr;
    }

    const tinytmx::Tileset* set = map->GetTileset(0); // Assuming only one tileset per area... CHANGE LATER!
    const tinytmx::Image* image = set->GetImage();
    const std::string tilepath = image->GetSource();

    SDL_Texture* tileset = loadTexture(tilepath, renderer);

    if (!set || !image || !tileset) {
        std::cerr << "Tileset allocation failed. Check tilemap metadata and ensure tileset path is correct/set to embedded." << SDL_GetError() << std::endl;
    }
    
    return tileset;

}

SDL_Texture* renderMap(tinytmx::Map* map, SDL_Texture* tileTex, SDL_Texture* mapTexture, const tinytmx::Tileset* tileset, SDL_Renderer* renderer) {

    if (!map || !tileTex || !mapTexture || !tileset || !renderer) {
        std::cerr << "One or more arguments are not initialized. If using a smart pointer for map, ensure it has been made unique." << SDL_GetError() << std::endl;
    }

    SDL_SetRenderTarget(renderer, mapTexture);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (int l = 0; l < map->GetNumLayers(); l++) {

        const tinytmx::Layer* layer = map->GetLayer(l); // Get layer... 0 for background (non colliding) 1 for foreground (colliding)

        if (!layer) {
            std::cerr << "Layer does not exist. Ensure tilemap is exported properly and/or not tampered with, as this error is caused by improper formatting or corruption of tilemap xml data." << std::endl;
        }

        if (!layer->IsVisible()) continue; // If layer is invisible, skip rendering
        
        int width = layer->GetWidth();
        int height = layer->GetHeight();
        
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int tileID = map->GetTileLayer(l)->GetDataTileFiniteMap()->GetTileGid(x, y); // Get tile ID from layer iteration
                if (tileID == 0) continue; // Empty tile, skip rendering
                
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

    SDL_SetRenderTarget(renderer, nullptr);

    return mapTexture;

}