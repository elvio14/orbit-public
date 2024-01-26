#pragma once

#include "CircleShape.h"
#include "Physics.h"
#include "Effect.h"
#include "BoostEffect.h"

class Ball
{
public:
	Ball(){
		b_xpos = 0.f;
		b_ypos = 0.f;
		b_velocity = Utils::Position(0.2f, -0.05f);
		b_rad = 4.f;

		b_circle.SetColor(1.f, 1.f, 0.f);
		b_circle.SetRadius(b_rad);
		b_circle.SetPosition(b_xpos, b_ypos);

		isActive = false;
		b_boost = 1.f;
	}

	Utils::Position getPosition() { return Utils::Position(b_xpos, b_ypos); }
	void setPosition(float x, float y) { b_xpos = x; b_ypos = y; }
	void setColor(float r, float g, float b) { b_circle.SetColor(r, g, b); }
	void makeActive() { isActive = true; }
	void boosting(std::vector<std::shared_ptr<Effect>>* effects);
	bool isInBound();
	void update();
	void render();

public:
	float b_xpos;
	float b_ypos;
	float b_rad;

	Utils::Position b_velocity; //using Position to contain velocity in x and y dimensions in one struct. Not resembling position.
	bool isActive;
	float b_boost;

private: 
	CircleShape b_circle;
};

