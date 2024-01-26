#include "stdafx.h"
#include "Player.h"

void Player::boosting(std::vector<std::shared_ptr<Effect>>* effects) {
	pr_ball.boosting(effects);
}

void Player::update(bool isWon) {
	if (isWon) {
		float x = pr_launcher.initialX;
		float y = pr_launcher.initialY;
		pr_launcher.setPosition(x,y);
		pr_ball.setPosition(x, y);
	}
}

void Player::render() {
	if (!pr_ball.isActive) {
		pr_launcher.render(pr_sign);
	}
	pr_ball.render();
}