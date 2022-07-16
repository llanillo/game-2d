#include <iostream>
#include "Headers/Engine/GameEngine.h"
#include <SDL.h>
#include <SDL_image.h>

GameEngine* GameEngineClass = nullptr;

int main(int argc, char* args []) {
    GameEngineClass = new GameEngine();
    GameEngineClass->Init("Testerino", SDL_WINDOWPOS_CENTERED,
                          SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while(GameEngineClass->IsRunning()){
        GameEngineClass->HandleEvents();
        GameEngineClass->Update();
        GameEngineClass->Render();
    }

    GameEngineClass->Clean();
    return 0;
}
