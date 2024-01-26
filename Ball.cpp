#include "stdafx.h"
#include "Ball.h"

void Ball::boosting(std::vector<std::shared_ptr<Effect>>* effects) {
	b_boost = -0.2f;
	BoostEffect::addBoost(*effects, b_xpos, b_ypos, 0.34f);
}

bool Ball::isInBound() {
	float offset = 2.f;
	if (b_xpos <= offset ||
		b_xpos >= APP_VIRTUAL_WIDTH - offset ||
		b_ypos <= offset ||
		b_ypos >= APP_VIRTUAL_HEIGHT - offset
		) {
		return false;
	}
	return true;
}

void Ball::update() {
	if (!isInBound()) {
		isActive = false;
	}
}

void Ball::render() {
	b_circle.SetPosition(b_xpos, b_ypos);
	b_circle.DrawFilled();
}