#pragma once
#include "Ball.h"
#include "Launcher.h"

class Player
{
public:
	Player() {
		pr_sign = 0.f;
		pr_ypos = 0.f;
	}
	Player(float sign) : pr_sign(sign) {
		float offset = 10.f;
		pr_ypos = Utils::app_height * pr_sign + pr_sign * -2.f * offset + offset;
		pr_launcher.initialY = pr_ypos;
		pr_launcher.l_ypos = pr_ypos;
		pr_launcher.l_angle += Utils::fPI * pr_sign;
		pr_ball.setPosition(pr_launcher.initialX, pr_launcher.initialY);
		pr_ball.setColor(
			//r,g,b
			0.f + pr_sign,
			1.f - pr_sign,
			0.f
		);
	}

	void addAngle(float angle) { pr_launcher.l_angle += angle; }
	void setBoost(float boost) { pr_ball.b_boost = boost; }
	bool isBallActive() { return pr_ball.isActive; }
	void launch() { pr_launcher.launchBall(pr_ball); }

	void boosting(std::vector<std::shared_ptr<Effect>>* effects);

	void update(bool isWon);
	void render();

public:
	float pr_sign;
	float pr_ypos;

	Ball pr_ball;
	Launcher pr_launcher;
};

