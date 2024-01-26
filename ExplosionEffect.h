#pragma once
#include "Effect.h"
#include "CircleShape.h"

class ExplosionEffect :
    public Effect
{
public:
    ExplosionEffect(float x, float y) : effect_(x, y), circle_() {
        particlesInit();
        circle_.SetColor(1.f, 0.f, 0.f);
    };

    void particlesInit();
    static void addExplosion(std::vector<std::shared_ptr<Effect>>& effects, float x, float y);
    void update(float deltaTime) override;
    void render() override;

private:
    Effect effect_;
    static constexpr int numParticles_ = 20;
    Effect::Particle particles_[numParticles_];
    CircleShape circle_;
    int maxFrames_ = 10;
    int frames_ = maxFrames_;
};