#pragma once
#include "App/app.h"
#include "stdafx.h"
#include "Utils.h"

class Shape
{
public:
	Shape() {
		s_xpos = 0.f;
		s_ypos = 0.f;
		s_cR = 1.f;
		s_cG = 1.f;
		s_cB = 1.f;
	};
	Shape(float x, float y, float r, float g, float b) : 
		s_xpos(x), s_ypos(y), s_cR(r), s_cG(g), s_cB(b) {}
	void SetPosition(float x, float y) { s_xpos = x; s_ypos = y; }
	void SetColor(float r, float g, float b) { s_cR = r; s_cG = g, s_cB = b; }

public:
	float s_xpos;
	float s_ypos;
	float s_cR;
	float s_cG;
	float s_cB;
};

