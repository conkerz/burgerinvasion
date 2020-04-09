#include <iostream>
#include <fstream>
#include <string>
#include "includes/bullet.hh"
#include "includes/game-info.hh"
#include "includes/sprite-db.hh"
#include <cmath>

Bullet::Bullet(bullettype t, sf::Vector2f pos, sf::Vector2f d)
    : MovingSprite()
{
    sprite_.setPosition(pos);
    dir = d;
    rot_ = 0.0;
    setbullet(t);
}

void Bullet::setbullet(bullettype type)
{
    if (type == B_SMALL)
    {
        sprite_.setTexture(*SpriteDB::t_bullet2, true);
        sprite_.setOrigin(7, 7);
        vit = 2;
        rotx_ = 10;
        range_ = 15;
        power_ = 10;
    }
    if (type == B_MEDIUM)
    {
        sprite_.setTexture(*SpriteDB::t_bullet1, true);
        sprite_.setOrigin(7, 7);
        vit = 2.5;
        rotx_ = 15;
        range_ = 15;
        power_ = 20;
    }
    if (type == B_BIG)
    {
        sprite_.setTexture(*SpriteDB::t_bullet3, true);
        sprite_.setOrigin(11, 11);
        vit = 2.25;
        rotx_ = 40;
        range_ = 20;
        power_ = 100;
    }
}

bool Bullet::updatebullet(sf::RenderWindow& window, sf::Time& time)
{
    MovingSprite::update(window, time);
    rot_ += rotx_;
    sprite_.setRotation(rot_);
    if (rot_ > 360)
        rot_ = 0;

    // Test outside of map
    float x = sprite_.getPosition().x;
    float y = sprite_.getPosition().y;
    if (x < 0 || y < 0 || x > WIDTH * TILE_WIDTH || y > HEIGHT * TILE_HEIGHT)
        return true;

    // Test collision
    GameInfo& game = GameInfo::getgame();
    for (Enemy* e : game.enemies)
    {
        if (collide(e))
        {
            game.player_score += power_;
            e->getreckt(power_);
            if (e->hp <= 0)
            {
                game.player_gold += e->gold * 2;
                game.removeenemie(e);
            }
            return true;
        }
    }

    return false;
}

bool Bullet::collide(Enemy* e)
{
    float dx = e->sprite_.getPosition().x + 16 - sprite_.getPosition().x;
    float dy = e->sprite_.getPosition().y + 16 - sprite_.getPosition().y;
    float distance = sqrt(dx * dx + dy * dy);
    if (distance < range_)
        return true;
    return false;
}
