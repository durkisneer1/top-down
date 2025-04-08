#pragma once
#include <KrakenEngine.hpp>

class Player
{
public:
    Player();
    ~Player() = default;

    void update(double dt);

    kn::math::Vec2 getPos() const;

private:
    kn::AnimationController anim;
    kn::Rect rect;
    kn::math::Vec2 pos;
    const double speed = 100;
};
