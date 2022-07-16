#include <iostream>
#include <chrono>
#include <SDL.h>
#include <SDL_image.h>
#include "Headers/Engine/GameEngine.h"

GameEngine* GameEngineClass = nullptr;

int main(int argc, char* args []) {
    GameEngineClass = new GameEngine();
    GameEngineClass->Init("Testerino", SDL_WINDOWPOS_CENTERED,
                          SDL_WINDOWPOS_CENTERED, 800, 600, false);

    auto LastTime = std::chrono::system_clock::now();

    while(GameEngineClass->IsRunning()){
        auto Current = std::chrono::system_clock::now();
        auto ElapsedTime = Current - LastTime;

        GameEngineClass->HandleEvents();
        GameEngineClass->Update(ElapsedTime.count());
        GameEngineClass->Render();

        LastTime = Current;
    }

    GameEngineClass->Clean();
    return 0;
}
