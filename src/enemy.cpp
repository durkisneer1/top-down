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

void Enemy::update(const double dt, const kn::Vec2 &target, const kn::Frame *frame)
{
    auto dirVec = kn::math::normalize(target - pos);
    pos += dirVec * speed * dt;
    rect.center(pos);

    kn::window::blit(*frame->tex, rect, frame->rect);
}

bool Enemy::isDead(std::vector<Bullet> &bullets)
{
    for (size_t i = 0; i < bullets.size(); i++)
    {
        auto &bullet = bullets.at(i);
        if ((bullet.getPos() - pos).getLength() < (bullet.radius + radius))
        {
            bullets.erase(bullets.begin() + i);
            health--;
            return health == 0;
        }
    }
    return false;
}

kn::Vec2 Enemy::getPos() const
{
    return pos;
}