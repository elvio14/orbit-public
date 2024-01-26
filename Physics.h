#pragma once
#include "Utils.h"
#include "Planet.h"
#include "Ball.h"
#include "Launcher.h"

class Ball;
class Launcher;

class Physics
{
public: 
	Physics(){}

public:
	static void updatePos(std::vector<Planet> planets, Ball& ball,  Launcher& launcher, float deltaTime);
};