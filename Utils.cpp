#include "stdafx.h"
#include "Utils.h"

const float Utils::fPI = 3.1415926f;

const float Utils::app_width = APP_VIRTUAL_WIDTH;
const float Utils::app_height = APP_VIRTUAL_HEIGHT;


float Utils::dotProduct(Position v1, Position v2) {
	return v1.x * v2.x + v1.y * v2.y;
}

float Utils::getLengthSq(Position vec) {
	return vec.x * vec.x + vec.y * vec.y;
}

float Utils::getLength(Position vec) {
	return static_cast<float>(sqrt(vec.x * vec.x + vec.y * vec.y));
}

Utils::Position Utils::getDifference(Utils::Position p1, Utils::Position p2) {
	float x = p1.x - p2.x;
	float y = p1.y - p2.y;

	return Utils::Position(x, y);
}