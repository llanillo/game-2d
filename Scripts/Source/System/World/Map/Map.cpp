#include "System/World/Map/Map.h"
#include "System/Texture/TextureManager.h"
#include "System/Engine/GameEngine.h"
#include "SDL_image.h"

Map::Map(int Array[MapWidth][MapHeight]){
    DirtTexture = TextureManager::LoadTexture(DirtTexturePath);
    GrassTexture = TextureManager::LoadTexture(GrassTexturePath);
    WaterTexture = TextureManager::LoadTexture(WaterTexturePath);

    Load(Array);

    SourceRect = new SDL_Rect();
    DestRect = new SDL_Rect();

    SourceRect->x = SourceRect->y = 0;
    SourceRect->w = DestRect->w = GameEngine::TileSize;
    SourceRect->h = DestRect->h = GameEngine::TileSize;
    DestRect->x = DestRect->y = 0;
}

Map::~Map() {
    SDL_DestroyTexture(GrassTexture);
    SDL_DestroyTexture(DirtTexture);
    SDL_DestroyTexture(WaterTexture);
}

void Map::Draw(){
    for (int i = 0; i < MapWidth; ++i) {
        for (int j = 0; j < MapHeight; ++j) {

            DestRect->x = j * GameEngine::TileSize;
            DestRect->y = i * GameEngine::TileSize;

            switch(MapArray[i][j]){
                case 0:
                    TextureManager::Draw(WaterTexture, SourceRect, DestRect);
                    break;
                case 1:
                    TextureManager::Draw(GrassTexture, SourceRect, DestRect);
                    break;
                case 2:
                    TextureManager::Draw(DirtTexture, SourceRect, DestRect);
                    break;
                default:
                    break;
            }
        }
    }
}

void Map::Load(int Array[MapWidth][MapHeight]){
    for (unsigned int i = 0; i < MapWidth; ++i) {
        for (int j = 0; j < MapHeight; ++j) {
            MapArray[i][j] = Array[i][j];
        }
    }
}
