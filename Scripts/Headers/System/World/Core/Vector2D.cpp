//
// Created by llani on 05/09/2022.
//

#include "Vector2D.h"

Vector2D &Vector2D::Add(const Vector2D &vector2D) {
    X += vector2D.X;
    Y += vector2D.Y;
    return *this;
}

Vector2D &Vector2D::Subtract(const Vector2D &vector2D) {
    X -= vector2D.X;
    Y -= vector2D.Y;
    return *this;
}

Vector2D &Vector2D::Multiply(const Vector2D &vector2D) {
    X *= vector2D.X;
    Y *= vector2D.Y;
    return *this;
}

Vector2D &Vector2D::Divide(const Vector2D &vector2D) {
    X /= vector2D.X;
    Y /= vector2D.Y;
    return *this;
}

Vector2D &operator+(Vector2D &vector1, const Vector2D &vector2) {
    return vector1.Add(vector2);
}

Vector2D &operator-(Vector2D &vector1, const Vector2D &vector2) {
    return vector1.Subtract(vector2);
}

Vector2D &operator*(Vector2D &vector1, const Vector2D &vector2) {
    return vector1.Multiply(vector2);
}

Vector2D &operator/(Vector2D &vector1, const Vector2D &vector2) {
    return vector1.Divide(vector2);
}

Vector2D &Vector2D::operator+=(const Vector2D &vector2D) {
    return this->Add(vector2D);
}

Vector2D &Vector2D::operator-=(const Vector2D &vector2D) {
    return this->Subtract(vector2D);
}

Vector2D &Vector2D::operator*=(const Vector2D &vector2D) {
    return this->Multiply(vector2D);
}

Vector2D &Vector2D::operator/=(const Vector2D &vector2D) {
    return this->Divide(vector2D);
}

std::ostream& operator<<(std::ostream& os, const Vector2D& vector2D){
    os << '(' << vector2D.X << ", " << vector2D.Y << ')';
    return os;
}
