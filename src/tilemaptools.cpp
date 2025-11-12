#include "headers/tilemaptools.hpp"
#include "headers/textureloader.hpp"
#include <memory>
#include "tinytmx.hpp"

SDL_Texture* initMapTexture(SDL_Renderer* renderer, tinytmx::Map* map) {

    int mapPixelW = map->GetWidth() * map->GetTileWidth();
    int mapPixelH = map->GetHeight() * map->GetTileHeight();

    SDL_Texture* mapTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, mapPixelW, mapPixelH); // Different from standard texture loading... Probably optional but it works

    return mapTexture;

}

SDL_Texture* createTileSetTexture(SDL_Renderer* renderer, tinytmx::Map* map) {

    const tinytmx::Tileset* set = map->GetTileset(0); // Assuming only one tileset per area... CHANGE LATER!
    const tinytmx::Image* image = set->GetImage();
    const std::string tilepath = image->GetSource();

    SDL_Texture* tileset = loadTexture(tilepath, renderer);
    
    return tileset;

}

SDL_Texture* renderMap(tinytmx::Map* map, SDL_Texture* tileTex, SDL_Texture* mapTexture, const tinytmx::Tileset* tileset, SDL_Renderer* renderer) {

    SDL_SetRenderTarget(renderer, mapTexture);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

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

    SDL_SetRenderTarget(renderer, nullptr);

    return mapTexture;

}