#pragma once
#include "Effect.h"
#include "CircleShape.h"

class BoostEffect :
    public Effect
{
public:
    BoostEffect(float x, float y) : effect_(x, y), circle_() {
        particlesInit();
        circle_.SetColor(1.f, 0.f, 0.f);
        radiusFactor_ = 1.f;
    }

    void particlesInit();
    void update(float deltaTime) override;
    void render() override;
    static void addBoost(std::vector<std::shared_ptr<Effect>>& effects, float x, float y);
    static void addBoost(std::vector<std::shared_ptr<Effect>>& effects, float x, float y, float radius);
    void setBoostRadius(float radius) { radiusFactor_ = radius; }

public:
    Effect effect_;
    CircleShape circle_;

    int maxFrames_ = 20;
    int frames_ = maxFrames_;
    float radiusFactor_;
    static constexpr int numParticles_ = 5;

    Effect::Particle particles_[numParticles_];
    
};

