#pragma once
#include "CircleShape.h"
#include "Player.h"

class Grid
{
public:
	Grid() {
		float cornerOffset = 40.f;
		float width = Utils::app_width;
		float height = Utils::app_height;
		//Manualy set bonus points, 4 corners and one center
		g_bonusPos[0] = Utils::Position( width / 2.f, height / 2.f); //center
		g_bonusPos[1] = Utils::Position(width - cornerOffset , height - cornerOffset);
		g_bonusPos[2] = Utils::Position(width - cornerOffset, cornerOffset);
		g_bonusPos[3] = Utils::Position(cornerOffset, height - cornerOffset);
		g_bonusPos[4] = Utils::Position(cornerOffset, cornerOffset);

		dotsInit();
		bonusInit();

		g_circle.SetColor(0.f, 0.f, 0.5f);
	}
	~Grid(){}

	void dotsInit();
	void bonusInit();
	void update(Player* players);
	void render();

public:
	const static int g_div = 20;
	const static int g_row = static_cast<int>(APP_VIRTUAL_WIDTH / g_div);
	const static int g_col = static_cast<int>(APP_VIRTUAL_HEIGHT / g_div);
	int g_grid[g_row][g_col];
	CircleShape g_circle;

	Utils::Position g_bonusPos[5];
};

