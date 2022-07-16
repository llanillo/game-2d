#include "Engine/TextureManager.h"
#include "SDL_image.h"
#include "SDL.h"

SDL_Texture* TextureManager::LoadTexture(const char* Texture, SDL_Renderer* Renderer){
    SDL_Surface* TempSurface = IMG_Load(Texture);
    SDL_Texture* Output = SDL_CreateTextureFromSurface(Renderer, TempSurface);
    SDL_FreeSurface(TempSurface);
    return Output;
}