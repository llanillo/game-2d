#ifndef INC_2D_MAP_H
#define INC_2D_MAP_H

class SDL_Rect;
class SDL_Texture;

const int MapWidth = 20;
const int MapHeight = 25;

class Map{

    const char* DirtTexturePath = "../Resources/Sprites/World/Map/Dirt.png";

    const char* GrassTexturePath = "../Resources/Sprites/World/Map/Grass.png";

    const char* WaterTexturePath = "../Resources/Sprites/World/Map/Water.png";

    SDL_Rect* SourceRect, *DestRect;

    SDL_Texture* DirtTexture, *GrassTexture, *WaterTexture;

    int MapArray[20][25] = {0};

public:

    explicit Map(int Array[MapWidth][MapHeight]);

    void Load(int Array[MapWidth][MapHeight]);

    void Draw();

    virtual ~Map();

};
#endif //INC_2D_MAP_H
