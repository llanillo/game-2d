#include "Template/GameObject.h"
#include "Engine/GameEngine.h"
#include "Engine/TextureManager.h"
#include <SDL.h>

GameObject::GameObject(const char* TextureSheet, int X, int Y){
    XPos = X;
    YPos = Y;

    SourceRect = new SDL_Rect();
    DestRect = new SDL_Rect();
    Texture = TextureManager::LoadTexture(TextureSheet);
}

GameObject::~GameObject(){

}

void GameObject::Render() {
    SDL_RenderCopy(GameEngine::Renderer, Texture, nullptr, DestRect);
}

void GameObject::Update(double DeltaTime){
//    XPos++;
//    YPos++;

    SourceRect->h = GameEngine::TileSize;
    SourceRect->w = GameEngine::TileSize;
    SourceRect->x = 0;
    SourceRect->y = 0;

    DestRect->x = XPos;
    DestRect->y = YPos;
    DestRect->w = SourceRect->w * 2;
    DestRect->h = SourceRect->h * 2;

}