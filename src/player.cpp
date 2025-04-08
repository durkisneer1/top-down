#include "Player.hpp"

Player::Player() : pos(kn::window::getSize() / 2)
{
    rect.size({48, 48});
    anim.loadSpriteSheet("walk", "../assets/player_walk.png", {48, 48}, 10);
}

void Player::update(const double dt)
{
    const auto* keys = kn::key::getPressed();
    kn::math::Vec2 dirVec = {
        keys[kn::S_d] - keys[kn::S_a],
        keys[kn::S_s] - keys[kn::S_w]
    };
    if (dirVec.getLength() > 1)
        dirVec.normalize();

    pos += dirVec * speed * dt;
    rect.center(pos);

    const auto* currFrame = anim.nextFrame(dt);
    kn::window::blit(*currFrame->tex, rect, currFrame->rect);
}

kn::math::Vec2 Player::getPos() const
{
    return pos;
}
