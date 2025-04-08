#include "Enemy.hpp"
#include "Bullet.hpp"

Enemy::Enemy()
{
    rect.size({16, 16});

    int borderSide = rand() % 4;
    auto winSize = kn::window::getSize();
    switch (borderSide)
    {
    case 0:
        pos.x = rand() % static_cast<int>(winSize.x);
        pos.y = 0;
        break;
    case 1:
        pos.x = winSize.x;
        pos.y = rand() % static_cast<int>(winSize.y);
        break;
    case 2:
        pos.x = rand() % static_cast<int>(winSize.x);
        pos.y = winSize.y;
        break;
    case 3:
        pos.x = 0;
        pos.y = rand() % static_cast<int>(winSize.y);
        break;
    }
}

void Enemy::update(const double dt, const kn::math::Vec2 &target, const kn::Frame *frame)
{
    auto diff = target - pos;
    if (diff.getLength() > 30)
    {
        auto dirVec = kn::math::normalize(diff);
        pos += dirVec * speed * dt;
        rect.center(pos);
    }

    kn::window::blit(*frame->tex, rect, frame->rect);
}

bool Enemy::isHit(const std::vector<Bullet> &bullets)
{
    for (const Bullet &bullet : bullets)
    {
        if ((bullet.getPos() - pos).getLength() < (bullet.radius + radius))
        {
            return true;
        }
    }
    return false;
}
