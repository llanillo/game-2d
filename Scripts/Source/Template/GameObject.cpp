#include "Template/GameObject.h"
#include <SDL.h>
#include "Engine/TextureManager.h"

GameObject::GameObject(const char* TextureSheet, SDL_Renderer* Renderer){
    this->Renderer = Renderer;
    Texture = TextureManager::LoadTexture(TextureSheet, Renderer);
}

