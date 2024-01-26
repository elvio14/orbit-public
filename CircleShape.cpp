#include "stdafx.h"
#include "CircleShape.h"

void CircleShape::Draw() {
	float currentX = s_xpos;
	float currentY = s_ypos - c_radius;

	for (float i = 0.f; i < 24.f; i++) {
		float angle = i * Utils::fPI / 12.f;
		float ex = currentX + cosf(angle)/ Utils::fPI * c_radius;
		float ey = currentY + sinf(angle)/ Utils::fPI * c_radius;

		App::DrawLine(currentX, currentY, ex, ey, s_cR, s_cG, s_cB);
		currentX = ex;
		currentY = ey;
	}
}

void CircleShape::DrawFilled() {
	for (float i = 0; i < 360; i++) {
		float angle = i * Utils::fPI / 180.f;
		float sx = s_xpos + cosf(angle) * c_radius + c_radius/Utils::fPI;
		float sy = s_ypos + sinf(angle) * c_radius + c_radius/Utils::fPI;
		float ex = s_xpos - cosf(angle) * c_radius + c_radius/Utils::fPI;
		float ey = s_ypos - sinf(angle) * c_radius + c_radius/Utils::fPI;
		App::DrawLine(sx, sy, ex, ey, s_cR, s_cG, s_cB);
	}
}