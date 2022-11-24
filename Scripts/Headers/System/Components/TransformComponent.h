#ifndef INC_2D_TRANSFORMCOMPONENT_H
#define INC_2D_TRANSFORMCOMPONENT_H

#include "System/Template/Component.h"

class Vector2D;

class TransformComponent: public Component{

    static const int Size;

    Vector2D* Position;

    Vector2D* Velocity;

    float Speed;

    int Height;

    int Width;

    int Scale;

public:

    TransformComponent();

    TransformComponent(float X, float Y);

    void Init() override;

    void Update(double DeltaTime) override;

    inline const Vector2D* GetPosition() const { return Position; }

    inline const Vector2D* GetVelocity() const { return Velocity; }

    inline float GetSpeed() const { return Speed; }

    inline int GetWidth() const { return Width; }

    inline int GetHeight() const { return Height; }

    inline int GetScale() const { return Scale; }
};

#endif //INC_2D_TRANSFORMCOMPONENT_H
