#ifndef INC_2D_VECTOR2D_H
#define INC_2D_VECTOR2D_H

#include <iostream>

class Vector2D {

public:

    float X;

    float Y;

    Vector2D() : X(0.f), Y(0.f){}

    Vector2D(float x, float y) : X(x), Y(y) {}

    Vector2D& Add(const Vector2D& vector2D);

    Vector2D& Subtract(const Vector2D& vector2D);

    Vector2D& Multiply(const Vector2D& vector2D);

    Vector2D& Divide(const Vector2D& vector2D);

    friend Vector2D& operator+(Vector2D& vector1, const Vector2D& vector2);

    friend Vector2D& operator-(Vector2D& vector1, const Vector2D& vector2);

    friend Vector2D& operator*(Vector2D& vector1, const Vector2D& vector2);

    friend Vector2D& operator/(Vector2D& vector1, const Vector2D& vector2);

    Vector2D& operator+=(const Vector2D& vector2D);

    Vector2D& operator-=(const Vector2D& vector2D);

    Vector2D& operator*=(const Vector2D& vector2D);

    Vector2D& operator/=(const Vector2D& vector2D);

    friend std::ostream& operator<<(std::ostream& os, const Vector2D& vector2D);
};


#endif //INC_2D_VECTOR2D_H
