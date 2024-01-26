#include "stdafx.h"
#include "BoostEffect.h"

void BoostEffect::particlesInit() {
	for (int i = 0; i < numParticles_; i++) {
		particles_[i] = Effect::Particle(effect_.origin_, 1.f, 1.f, 1.f);
	}
}

void BoostEffect::update(float deltaTime) {
	if (frames_ == 0) {
		frames_ = maxFrames_;
		this->makeDone();
	}
	else {
		for (auto& particle : particles_) {
			float random = static_cast<float>(rand() % 2 - rand() % 2);
			particle.pos.x += random * deltaTime / 10.f;
			particle.pos.y += random * deltaTime / 10.f;
		}
		frames_--;
	}
}

void BoostEffect::render() {
	for (auto& particle : particles_) {
		float radius = static_cast<float>(frames_) * 0.5f * radiusFactor_;
		circle_.SetRadius(radius);

		float b = static_cast<float>(frames_) / static_cast<float>(maxFrames_);
		circle_.SetColor(1.f, 1.f - b, b);
		circle_.SetPosition(particle.pos.x, particle.pos.y);
		circle_.DrawFilled();
	}
}

void BoostEffect::addBoost(std::vector<std::shared_ptr<Effect>>& effects, float x, float y) {
	auto boost = std::make_shared<BoostEffect>(x, y);
	effects.push_back(boost);
}

void BoostEffect::addBoost(std::vector<std::shared_ptr<Effect>>& effects, float x, float y, float radius) {
	auto boost = std::make_shared<BoostEffect>(x, y);
	boost->setBoostRadius(radius);
	effects.push_back(boost);
}