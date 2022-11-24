#include "System/Engine/GameEngine.h"
#include "System/Engine/EntityManager.h"
#include "System/Components/TransformComponent.h"
#include "System/Components/SpriteComponent.h"
#include "System/Components/ColliderComponent.h"
#include "System/Template/Component.h"
#include "System/Template/Entity.h"
#include "System/World/Core/Vector2D.h"
#include "System/World/Map/Map.h"
#include "System/Input/KeyboardController.h"
#include "SDL.h"

SDL_Renderer* GameEngine::Renderer = nullptr;
SDL_Event* GameEngine::Event;

GameEngine::GameEngine(){
    MainManager = new EntityManager();
    Player = &MainManager->AddEntity();
}

GameEngine::~GameEngine(){

}

void GameEngine::Init(const char *Title, int XPos, int YPos, int Width, int Height, bool Fullscreen) {
    int Flags = 0;

    if(Fullscreen){
        Flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        Window = SDL_CreateWindow(Title, XPos, YPos, Width, Height, Flags);
        Renderer = SDL_CreateRenderer(Window, -1, 0);

        if(Window && Renderer){
            bIsRunning = true;
            SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);

            int MapArray [MapWidth][MapHeight] = {0};

            WorldMap = new Map(MapArray);
            Player->AddComponent<TransformComponent>(100, 100);
            Player->AddComponent<SpriteComponent>(PlayerSpritePath);
            Player->AddComponent<KeyboardController>();
        }
        else{
            bIsRunning = false;
        }
    }
}

void GameEngine::Render() {
    SDL_RenderClear(Renderer);
    Player->Draw();
    WorldMap->Draw();
    MainManager->Draw();
    SDL_RenderPresent(Renderer);
}

void GameEngine::Update(double ElapsedTime) {
    Player->Update(ElapsedTime);
    MainManager->Refresh();
    MainManager->Update(ElapsedTime);
}

void GameEngine::Clean() {
    SDL_DestroyWindow(Window);
    SDL_DestroyRenderer(Renderer);
    SDL_Quit();
}

void GameEngine::HandleEvents(){
    SDL_Event Event;
    SDL_PollEvent(&Event);

    switch(Event.type){
        case SDL_QUIT:
            bIsRunning = false;
            break;
        default:
            break;
    }
}

