#pragma once
#include "Shape.h"

class CircleShape :
    public Shape
{
public:
    CircleShape() {
        c_radius = 4.f;
    };
    CircleShape(float radius, float x, float y, float r, float g, float b):
        Shape(x, y, r, g, b), c_radius(radius) {};
    void Draw();
    void DrawFilled();
    void SetRadius(float radius) { c_radius = radius; }

private:
    float c_radius;
};

