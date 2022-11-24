#include "System/Components/SpriteComponent.h"
#include "System/Components/TransformComponent.h"
#include "System/Template/Entity.h"
#include "System/Texture/TextureManager.h"
#include "System/Engine/GameEngine.h"
#include "System/World/Core/Vector2D.h"
#include <SDL_image.h>

SpriteComponent::SpriteComponent() :SourceRect(new SDL_Rect()), DestRect(new SDL_Rect()){ }

SpriteComponent::SpriteComponent(const char *path) : SpriteComponent(){
    SetTexture(path);
}

void SpriteComponent::Init() {
    Transform = &Entity->GetComponent<TransformComponent>();

    SourceRect->x = SourceRect->y = 0;
    SourceRect->w = Transform->GetWidth();
    SourceRect->h = Transform->GetHeight();
    DestRect->w = DestRect->h = GameEngine::TileSize;
}

void SpriteComponent::Update(double DeltaTime) {
    DestRect->x = static_cast<int>(Transform->GetPosition()->X * DeltaTime);
    DestRect->y = static_cast<int>(Transform->GetPosition()->Y * DeltaTime);
    DestRect->w = Transform->GetWidth() * Transform->GetScale();
    DestRect->h = Transform->GetHeight() * Transform->GetScale();
}

void SpriteComponent::Draw() {
    TextureManager::Draw(Texture, SourceRect, DestRect);
}

void SpriteComponent::SetTexture(const char* path) {
    Texture = TextureManager::LoadTexture(path);
}

void SpriteComponent::Destroy() {
    Component::Destroy();
}

SpriteComponent::~SpriteComponent() {
    SDL_DestroyTexture(Texture);
}
