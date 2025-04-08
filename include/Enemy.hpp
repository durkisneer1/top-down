#pragma once
#include <KrakenEngine.hpp>
#include <vector>

class Bullet;

class Enemy
{
public:
    Enemy();
    ~Enemy() = default;

    void update(double dt, const kn::math::Vec2 &target, const kn::Frame* frame);

    bool isHit(const std::vector<Bullet>& bullets);

    double radius = 10.0;

private:
    kn::math::Vec2 pos;
    kn::Rect rect;
    double speed = 80;
};
