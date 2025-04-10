#pragma once
#include <KrakenEngine.hpp>

class Player
{
public:
    Player();
    ~Player() = default;

    void update(double dt);

    kn::Vec2 getPos() const;

    kn::Rect getRect() const;

private:
    kn::AnimationController anim;
    kn::Rect rect;
    kn::Vec2 pos;
    const double speed = 100;
};
