#include "stdafx.h"
#include "Launcher.h"

void Launcher::launchBall(Ball& ball) {
	float multiplier = 0.05f;
	if (l_xpos != initialX && l_ypos != initialY) {
		multiplier *= 1.8f;
	}
	ball.b_velocity.x = static_cast<float>(sin(l_angle)) * multiplier;
	ball.b_velocity.y = static_cast<float>(cos(l_angle)) * multiplier;

	ball.makeActive();
}

void Launcher::resetBall(Ball& ball) {
	ball.b_xpos = l_xpos;
	ball.b_ypos = l_ypos;
}

void Launcher::render(float sign) {

	float offset = 13.f;
	for (float i = 0; i < 15.f; i++) {
		//rendering dots with increasing distances between
		float y = static_cast<float>(cos(l_angle)) * (offset + i * 2.f) * i * 0.5f;
		float x = static_cast<float>(sin(l_angle)) * (offset + i * 2.f) * i * 0.5f;
		l_circle.SetPosition(l_xpos + x,l_ypos + y);
		l_circle.SetColor
		(
			//r , g , b
			1.f - i / 15.f + 0.3f * sign,
			1.f - i / 15.f + 0.3f * (1.f - sign),
			1.f - i / 15.f);
		l_circle.DrawFilled();
	}
	l_circle.SetPosition(l_xpos, l_ypos);
}