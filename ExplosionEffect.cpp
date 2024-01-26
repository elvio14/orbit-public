#include "stdafx.h"
#include "ExplosionEffect.h"

void ExplosionEffect::particlesInit() {
	for (int i = 0; i < numParticles_; i++) {
		particles_[i] = Effect::Particle(effect_.origin_, 1.f, 1.f, 1.f);
	}
}

void ExplosionEffect::addExplosion(std::vector<std::shared_ptr<Effect>>& effects, float x, float y) {
	auto explosion = std::make_shared<ExplosionEffect>(x, y);
	effects.push_back(explosion);
}

void ExplosionEffect::update(float deltaTime) {
	float angle = 0.f;

	if (frames_ == 0) {
		frames_ = maxFrames_;
		this->makeDone();
	}
	else {
		float increment = Utils::fPI / 10.f;
		float angle = 0.f;
		for (auto& particle : particles_) {
			float random = Utils::getRandomFloat();
			float multiplier = (static_cast<float>(maxFrames_) - static_cast<float>(frames_)) * 0.1f;
			particle.pos.x += cos(angle)  * multiplier;
			particle.pos.y += sin(angle) * multiplier;
			angle += increment;
		}
		frames_--;
	}
}

void ExplosionEffect::render() {
	for (auto& particle : particles_) {
		circle_.SetPosition(particle.pos.x, particle.pos.y);
		circle_.DrawFilled();
	}
}