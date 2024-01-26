#pragma once
#include "CircleShape.h"
#include "Ball.h"

class Ball;

class Launcher
{
public:
	Launcher() {
		initialY = 0.f;
		initialX = Utils::app_width / 2.f;
		l_angle = 0.f;
		l_xpos = initialX;
		l_ypos = initialY;
		l_circle.SetPosition(l_xpos, l_ypos);
		l_circle.SetRadius(2.f);
	}
	~Launcher(){}

public:
	void setPosition(float x, float y) { l_xpos = x; l_ypos = y; }
	void launchBall(Ball& ball);
	void resetBall(Ball& ball);
	void render(float sign);

public:
	float initialX;
	float initialY;
	float l_angle;
	float l_xpos;
	float l_ypos;

private:
	CircleShape l_circle;
};

