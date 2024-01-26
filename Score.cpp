#include "stdafx.h"
#include "Score.h"

void Score::rematch(Grid* grid) {
	isWon = false;
	s_winner = "";

	grid->dotsInit();
	grid->bonusInit();
}

void Score::update(const Grid* grid) {
	s_0 = -1;
	s_1 = -1;
	for (int i = 0; i < grid->g_row; i++) {
		for (int j = 0; j < grid->g_col; j++) {
			switch (grid->g_grid[i][j]) {
			case 0:
				s_0++;
				break;

			case 1:
				s_1++;
				break;

			case 10:
				s_0 += 150;
				break;

			case 11:
				s_1 += 150;
				break;

			default:
				break;
			}
		}
	}
	if (s_0 >= 1000) {
		isWon = true;
		s_winner = "Green";
	}

	if (s_1 >= 1000) {
		isWon = true;
		s_winner = "Red";
	}
}

void Score::render() {
	
	std::string s_0string = std::to_string(s_0);
	App::Print(s_0posX, s_0posY, s_0string.c_str(), 0.f,1.f,0.f, GLUT_BITMAP_HELVETICA_12);

	std::string s_1string = std::to_string(s_1);
	App::Print(s_1posX, s_1posY, s_1string.c_str(), 1.f, 0.f, 0.f, GLUT_BITMAP_HELVETICA_12);

	if (isWon) {
		std::string won = s_winner + " Wins! Hit BACKSPACE for a rematch.";
		float r = 0.f;
		float g = 0.f;
		if (s_winner == "Green") {
			r = 0.f;
			g = 1.f;
		}
		if (s_winner == "Red") {
			r = 1.f;
			g = 0.f;
		}
		App::Print(Utils::app_width / 2.f - 180.f, Utils::app_height / 2.f, won.c_str(), r, g, 0.f);
	}
}