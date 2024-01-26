#pragma once
#include "App/app.h"

class Utils
{
public:
	//Position as 'vector'
	struct Position {
		float x;
		float y;

		Position() : x(0.f), y(0.f) {}

		Position(float x, float y) : x(x), y(y) {}
	};

	struct Projection {
		float min;
		float max;
	};

	static Position getDifference(Position p1, Position p2);
	static float dotProduct(Position v1, Position v2);
	static float getLengthSq(Position vec);
	static float getLength(Position vec);
	static float getRandomFloat() { return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);}

public:
	static const float fPI;
	static const float app_width;
	static const float app_height;
};

