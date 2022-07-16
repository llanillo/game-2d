#include "Engine/GameEngine.h"
#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include <SDL_rect.h>

GameEngine::GameEngine(){


}

GameEngine::~GameEngine(){

}

void GameEngine::Init(const char *Title, int XPos, int YPos, int Width, int Height, bool Fullscreen) {
    int Flags = 0;

    if(Fullscreen){
        Flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "Subsystems initialised...\n";
        Window = SDL_CreateWindow(Title, XPos, YPos, Width, Height, Flags);

        if(Window){
            std::cout << "Window created\n";
            Renderer = SDL_CreateRenderer(Window, -1, 0);

            if(Renderer){
                std::cout << "Renderer created\n";
                SDL_SetRenderDrawColor(Renderer, 255, 255, 255 , 255);
                bIsRunning = true;
            }
            else{
                bIsRunning = false;
            }
        }
        else{
            bIsRunning = false;
        }
    }

    SDL_Surface* TmpSurface = IMG_Load("Assets/Player/Player.png");
    PlayerTexture = SDL_CreateTextureFromSurface(Renderer, TmpSurface);
    SDL_FreeSurface(TmpSurface);

    SourceRectangle = new SDL_Rect();
    DestinationRectangle = new SDL_Rect();
}

void GameEngine::Render() {
    SDL_RenderClear(Renderer);
    SDL_RenderCopy(Renderer, PlayerTexture, nullptr, DestinationRectangle);
    SDL_RenderPresent(Renderer);
}

void GameEngine::Update(double ElapsedTime) {
    Counter++;

    DestinationRectangle->h = 64;
    DestinationRectangle->w = 64;
//    DestinationRectangle->x = Counter;
}

void GameEngine::Clean() {
    SDL_DestroyWindow(Window);
    SDL_DestroyRenderer(Renderer);
    SDL_Quit();
    std::cout << "Game Cleaned\n";
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

