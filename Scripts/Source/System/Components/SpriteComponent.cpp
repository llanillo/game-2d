#include "System/Components/SpriteComponent.h"
#include "System/Components/PositionComponent.h"
#include "System/Template/Entity.h"
#include "System/Texture/TextureManager.h"
#include "System/Engine/GameEngine.h"
#include <SDL_image.h>

SpriteComponent::SpriteComponent() {
    SourceRect = new SDL_Rect();
    DestRect = new SDL_Rect();
}

SpriteComponent::SpriteComponent(const char *path) : SpriteComponent(){
    SetTexture(path);
}

void SpriteComponent::Init() {
    Position = &Entity->GetComponent<PositionComponent>();

    SourceRect->x = SourceRect->y = 0;
    SourceRect->w = SourceRect->h = GameEngine::TileSize / 2;
    DestRect->w = DestRect->h = GameEngine::TileSize;
}

void SpriteComponent::Update(double DeltaTime) {
    DestRect->x = Position->GetXPos() * static_cast<int>(DeltaTime);
    DestRect->y = Position->GetYPos() * static_cast<int>(DeltaTime);
}

void SpriteComponent::Draw() {
    TextureManager::Draw(Texture, SourceRect, DestRect);
}

void SpriteComponent::SetTexture(const char* path) {
    Texture = TextureManager::LoadTexture(path);
}
