#include "stdafx.h"
#include "RectangleShape.h"
#include "app\app.h"

void RectangleShape::Draw() {
	float x = s_xpos - 0.5f*r_width;
	float y = s_ypos;
	float w = r_width;
	float h = r_height;

	float r = s_cR;
	float g = s_cG;
	float b = s_cB;

	//Bottom Border
	App::DrawLine(x, y, x+w, y, r, g, b);

	//Top Border
	App::DrawLine(x, y+h, x+w, y+h, r, g, b);

	//Left Border
	App::DrawLine(x, y, x, y+h, r, g, b);

	//Right Border
	App::DrawLine(x+w, y, x+w, y+h, r, g, b);
}

void RectangleShape::DrawFilled() {
	float height = r_height;
	float width = r_width;
	for (float i = 0.f; i < height; i++) {
		App::DrawLine(s_xpos, s_ypos + i, s_xpos + width, s_ypos + i, s_cR, s_cG, s_cB);
	}
}