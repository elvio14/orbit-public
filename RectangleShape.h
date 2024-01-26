#pragma once
#include "Shape.h"
class RectangleShape :
    public Shape
{
public: 
    virtual ~RectangleShape() {};
    RectangleShape() {
        r_width = 0.f;
        r_height = 0.f;
    }
    RectangleShape(float width, float height, float x, float y, float r, float g, float b):
        r_width(width), r_height(height), Shape(x, y, r, g, b) {};

    void Draw();
    void DrawFilled();
    void SetWidth(float width) { r_width = width; }
    void SetHeight(float height) { r_height = height; }
    //void SetPosition(float x, float y) { s_xpos = x; s_ypos = y; }
    //void SetColor(float r, float g, float b) { s_cR = r; s_cG = g; s_cB = b;}

public:
    float r_width;
    float r_height;
};

