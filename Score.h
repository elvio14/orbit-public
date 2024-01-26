#pragma once
#include "Grid.h"
#include "RectangleShape.h"

class Score
{
public:
	Score(){
		s_0 = -1;
		s_1 = -1;
		isWon = false;
		s_winner = "";

		float offsetY = 20.f;
		float offsetX = 60.f;
		s_0posX = Utils::app_width / 2.f - offsetX;
		s_0posY = offsetY;
		s_1posX = Utils::app_width / 2.f + offsetX;
		s_1posY = offsetY;
	}

	void rematch(Grid* grid);
	bool getStatus() { return isWon; }

	void update(const Grid* grid);
	void render();

public:
	int s_0;
	int s_1;

	bool isWon;
	std::string s_winner;

	float s_0posX;
	float s_0posY;
	float s_1posX;
	float s_1posY;
};

