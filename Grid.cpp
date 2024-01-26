#include "stdafx.h"
#include "Grid.h"

void Grid::dotsInit() {
	for (int i = 0; i < g_row; i++) {
		for (int j = 0; j < g_col; j++) {
			g_grid[i][j] = -1;
		}
	}
}

void Grid::bonusInit() {
	for (int i = 0; i < 5; i++) {
		float x = g_bonusPos[i].x;
		float y = g_bonusPos[i].y;

		int indexX = static_cast<int>(std::round(x / g_div));
		int indexY = static_cast<int>(std::round(y / g_div));

		g_grid[indexX][indexY] = 9;
		//default bonus state = 9.
	}
}

void Grid::update(Player* players){
	for (int i = 0; i < 2; i++) {
		bool inBound = players[i].pr_ball.isInBound();

		if (inBound) {
			float x = players[i].pr_ball.b_xpos;
			float y = players[i].pr_ball.b_ypos;

			int indexX = static_cast<int>(std::round(x / g_div));
			int indexY = static_cast<int>(std::round(y / g_div));

			int value = g_grid[indexX][indexY];

			if (value > 1) {
				g_grid[indexX][indexY] = 10 + i; // Bonus points states updated by players to either 10 or 11.
			}
			else {
				g_grid[indexX][indexY] = i; //Regular points states updated by players to either 0 or 1
			}
		}
	}
}

void Grid::render() {
	
	for (int i = 0; i < g_row; i++) {
		for (int j = 0; j < g_col; j++) {
			float x = 0.f + static_cast<float>(g_div * i);
			float y = 0.f + static_cast<float>(g_div * j);
			g_circle.SetPosition(x, y);

			switch (g_grid[i][j]) {
				case 0:  
					g_circle.SetColor(0.2f, 0.3f, 0.2f);
					g_circle.SetRadius(2.f);
					g_circle.Draw();
					break;

				case 1:
					g_circle.SetColor(0.3f, 0.2f, 0.2f);
					g_circle.SetRadius(2.f);
					g_circle.Draw();
					break;

				case -1:
					g_circle.SetColor(0.f, 0.f, 0.2f);
					g_circle.SetRadius(2.f);
					g_circle.Draw();
					break;

				//Bonuses
				case 9:
					g_circle.SetColor(0.f, 0.f, 0.8f);
					g_circle.SetRadius(8.f);
					g_circle.DrawFilled();
					break;
				case 10:
					g_circle.SetColor(0.2f, 0.8f, 0.2f);
					g_circle.SetRadius(8.f);
					g_circle.DrawFilled();
					break;
				case 11:
					g_circle.SetColor(0.8f, 0.2f, 0.2f);
					g_circle.SetRadius(8.f);
					g_circle.DrawFilled();
					break;
			}
			
		}
	}
}