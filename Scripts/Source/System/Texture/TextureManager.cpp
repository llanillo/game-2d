#include "System/Texture/TextureManager.h"
#include "System/Engine/GameEngine.h"
#include "SDL_image.h"
#include "SDL.h"

SDL_Texture* TextureManager::LoadTexture(const char* Texture){
    SDL_Texture* Output = nullptr;
    SDL_Surface* TempSurface = IMG_Load(Texture);

    if(TempSurface){
        Output = SDL_CreateTextureFromSurface(GameEngine::Renderer, TempSurface);
        SDL_FreeSurface(TempSurface);
    }
    return Output;
}

void TextureManager::Draw(SDL_Texture* Texture, SDL_Rect* SourceRect, SDL_Rect* DestRect) {
    SDL_RenderCopy(GameEngine::Renderer, Texture, SourceRect, DestRect);
}
