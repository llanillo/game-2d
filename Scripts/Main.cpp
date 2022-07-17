#include <iostream>
#include <chrono>
#include <SDL.h>
#include "Headers/Engine/GameEngine.h"

int main(int argc, char* args []) {
    auto* GameEngineClass = new GameEngine();
    GameEngineClass->Init("Test", SDL_WINDOWPOS_CENTERED,
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
    delete GameEngineClass;
    return 0;
}
