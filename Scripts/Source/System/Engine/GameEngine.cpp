#include "System/Engine/GameEngine.h"
#include "System/Engine/Manager.h"
#include "System/Template/Entity.h"
#include "System/Components/PositionComponent.h"
#include "System/World/Map/Map.h"
#include "SDL.h"
#include <iostream>

SDL_Renderer* GameEngine::Renderer = nullptr;

GameEngine::GameEngine(){
    MainManager = new Manager();
    NewPlayer = &MainManager->AddEntity();
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

            Player = new GameObject(PlayerSpritePath, -1, 0);
            Enemy = new GameObject(EnemySpritePath, 49, 50);

            int MapArray [MapWidth][MapHeight] = {0};
            WorldMap = new Map(MapArray);

            NewPlayer->AddComponent<PositionComponent>();
        }
        else{
            bIsRunning = false;
        }
    }
}

void GameEngine::Render() {
    SDL_RenderClear(Renderer);
    WorldMap->Draw();
    Player->Draw();
    Enemy->Draw();
    SDL_RenderPresent(Renderer);
}

void GameEngine::Update(double ElapsedTime) {
    Player->Update(ElapsedTime);
    Enemy->Update(ElapsedTime);
    MainManager->Update(ElapsedTime);
//    std::cout << NewPlayer->GetComponent<PositionComponent>().GetXPos() << ", " <<
//        NewPlayer->GetComponent<PositionComponent>().GetYPos() << '\n';
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

