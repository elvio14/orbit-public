#pragma once

#include "Utils.h"

class Effect
{
public:

	struct Particle {
		Utils::Position pos;
		float r;
		float g;
		float b;

		Particle() {
			pos = Utils::Position(0.f, 0.f);
			r = 1.f;
			g = 1.f;
			b = 1.f;
		}

		Particle(Utils::Position pos, float r, float g, float b) : pos(pos), r(r), g(g), b(b) {};
	};

public:
	virtual ~Effect() {}

public:
	Effect() : origin_(0.f, 0.f) {};
	Effect(float x, float y) : origin_(x,y){};

public:
	virtual void update(float deltaTime){}
	virtual void render(){}
	virtual void makeDone() { isDone = true; }

public:
	Utils::Position origin_;
	bool isDone = false;
};

