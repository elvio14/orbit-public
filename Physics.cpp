#include "stdafx.h"
#include "Physics.h"

void Physics::updatePos(std::vector<Planet> planets, Ball& ball, Launcher& launcher, float deltaTime) {
	for (auto& planet : planets) {
		
		Utils::Position difference = Utils::getDifference(planet.getPosition(), ball.getPosition());
		float distance = Utils::getLength(difference);

		if (distance >= planet.p_rad + ball.b_rad) {

			float directionX = difference.x / distance;
			float directionY = difference.y / distance;
			float g = planet.p_mass / distance; //Scalar Gravity Acceleration

			float aX = g * directionX;	//Vector Acceleration
			float aY = g * directionY;

			ball.b_velocity.x += aX * deltaTime * ball.b_boost;
			ball.b_velocity.y += aY * deltaTime * ball.b_boost;

			ball.b_xpos += ball.b_velocity.x * deltaTime;
			ball.b_ypos += ball.b_velocity.y * deltaTime;
		}
		else {
			ball.b_velocity.x = 0.f;
			ball.b_velocity.y = 0.f;

			Utils::Position difference = Utils::getDifference(planet.getPosition(), ball.getPosition());
			float distance = Utils::getLength(difference);
			float directionX = difference.x / distance;
			float directionY = difference.y / distance;

			float newX = ball.b_xpos - directionX * 1.5f;
			float newY = ball.b_ypos - directionY * 1.5f;

			launcher.setPosition(newX, newY);
			ball.isActive = false;
		}
	}
}