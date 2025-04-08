#include <KrakenEngine.hpp>
#include <vector>

#include "Player.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"

int main()
{
    srand(time(0));

    kn::window::init({200, 150}, "Topdown Shooter", 4);
    kn::Event event;
    kn::time::Clock clock;

    Player player;

    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;
    enemies.push_back(Enemy());

    kn::AnimationController enemyAnim;
    enemyAnim.loadSpriteSheet("walk", "../assets/chk_walk.png", {16, 16}, 4);

    while (kn::window::isOpen())
    {
        const double dt = clock.tick() / 1000;
        while (kn::window::pollEvent(event))
        {
            if (event.type == kn::MOUSEBUTTONDOWN)
            {
                if (event.button.button == kn::M_LEFT)
                {
                    bullets.emplace_back(player.getPos());
                }
            }
        }
        kn::window::clear();

        player.update(dt);

        const kn::Frame* currFrame = enemyAnim.nextFrame(dt);
        for (Enemy &enemy : enemies)
        {
            enemy.update(dt, player.getPos(), currFrame);
        }

        size_t bulletRemoveIdx = -1;
        for (size_t i = 0; i < bullets.size(); i++)
        {
            auto &bullet = bullets.at(i);
            bullet.move(dt);
            if (bullet.outOfBounds())
                bulletRemoveIdx = i;
        }
        if (bulletRemoveIdx != -1)
            bullets.erase(bullets.begin() + bulletRemoveIdx);

        kn::window::flip();
    }
    kn::window::quit();
    return EXIT_SUCCESS;
}
