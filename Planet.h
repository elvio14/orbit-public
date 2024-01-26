#pragma once

#include "CircleShape.h"

class Planet
{
public: 
	Planet(float x, float y, float rad) : p_xpos(x), p_ypos(y), p_rad(rad) {
		max_rad = 12.f;
		float ratio = p_rad / max_rad;
		p_cR = 0.f + ratio;
		p_cG = 0.f + ratio;
		p_cB = 1.f;
		p_mass = 0.01f * ratio;
		p_circle.SetRadius(rad);
		p_circle.SetColor(p_cR, p_cG, p_cB);
		p_circle.SetPosition(x, y);
	}
	~Planet(){}

public: 
	Utils::Position getPosition() { return Utils::Position(p_xpos, p_ypos); }
	void setColor(float r, float g, float b) { p_cR = r; p_cG = g; p_cB = b; }
	void render();
	
public:
	float p_xpos;
	float p_ypos;
	float p_rad;

	float p_mass;
	float max_rad;

private:
	float p_cR;
	float p_cG;
	float p_cB;

	CircleShape p_circle;
};

