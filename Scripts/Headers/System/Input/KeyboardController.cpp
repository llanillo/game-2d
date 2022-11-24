#include "KeyboardController.h"
#include "System/Components/TransformComponent.h"
#include "System/Template/Entity.h"
#include "System/Engine/GameEngine.h"
#include "System/World/Core/Vector2D.h"
#include "SDL.h"

KeyboardController::~KeyboardController() {

}

void KeyboardController::Update(double DeltaTime) {
    Component::Update(DeltaTime);

    if (GameEngine::Event->type == SDL_KEYDOWN) {
        switch (GameEngine::Event->key.keysym.sym) {
            case SDLK_w:
                Transform->Velocity->Y -= -1;
                break;
            case SDLK_a:
                Transform->Velocity->X -= 1;
                break;
            case SDLK_d:
                Transform->Velocity->X += 1;
            case SDLK_s:
                Transform->Velocity->Y += 1;
            default:
                break;
        }
    }

    if (GameEngine::Event->type == SDL_KEYUP) {
        switch (GameEngine::Event->key.keysym.sym) {
            case SDLK_w:
                Transform->Velocity->Y = 0;
                break;
            case SDLK_a:
                Transform->Velocity->X = 0;
                break;
            case SDLK_d:
                Transform->Velocity->X = 0;
            case SDLK_s:
                Transform->Velocity->Y = 0;
            default:
                break;
        }
    }
}

void KeyboardController::Init() {
    Component::Init();
    Transform = &Entity->GetComponent<TransformComponent>();
}

void KeyboardController::Draw() {
    Component::Draw();
}

void KeyboardController::Destroy() {
    Component::Destroy();
}
