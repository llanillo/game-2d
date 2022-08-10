#ifndef INC_2D_GAMEENGINE_H
#define INC_2D_GAMEENGINE_H

class SDL_Window;
class SDL_Renderer;
class SDL_Texture;
class SDL_Rect;
class GameObject;
class EntityManager;
class Entity;
class Map;

class GameEngine {
public:

    GameEngine();
    ~GameEngine();

    void Init(const char* Title, int XPos, int YPos, int Width, int Height, bool Fullscreen);

    void HandleEvents();
    void Update(double DeltaTime);
    void Render();
    void Clean();

    static SDL_Renderer* Renderer;
    const static int TileSize = 64;

    inline bool IsRunning() const { return bIsRunning; }

private:

    bool bIsRunning;

    const char* PlayerSpritePath = "../Assets/Sprites/Player/Player.png";

    EntityManager* MainManager;
    Map* WorldMap;
    Entity* Player;

    SDL_Window* Window;
    SDL_Rect* SourceRect, *DestRect;
};


#endif //INC_2D_GAMEENGINE_H
