#include <cmath>
#include <iostream>

#include "../includes/tower.hh"
#include "../includes/game-info.hh"

    Tower::Tower(sf::Texture& text)
    : MySprite(text)
    , range_(32 * 4.5f)
    , speed_(65)
    , max_speed_(speed_)
      , BT_(B_MEDIUM)
{
    resize(0.40, 0.40);
}

    Tower::Tower(sf::Texture& text, int dmg, int range, int speed)
    : MySprite(text)
    , dmg_(dmg)
    , range_(range)
      , speed_(speed)
      , max_speed_(speed)
{}

bool Tower::is_in_range(Enemy& target)
{
    float x = sprite_.getPosition().x + 16;
    float y = sprite_.getPosition().y + 16;
    float tx = target.sprite_.getPosition().x + 16;
    float ty = target.sprite_.getPosition().y + 16;
    if (sqrt(pow((tx - x), 2) + pow(ty - y, 2)) < range_)
        return true;
    return false;
}

Enemy* Tower::get_target()
{
    GameInfo& game = GameInfo::getgame();
    std::list<Enemy*> enemies = game.enemies;
    for (auto i: enemies)
    {
        if (is_in_range(*i))
            return i;
    }
    return nullptr;
}

void Tower::update_tower()
{
    if (speed_ == max_speed_)
    {
        Enemy* tmp = get_target();
        if (!tmp)
            return;
        else
        {
            attack(tmp);
            speed_ = 0;
        }
    }
    else
        ++speed_;
}

void Tower::attack(Enemy* enemy)
{
    GameInfo& game = GameInfo::getgame();
    // bullet(type de munition, position de depart, direction)
    sf::Vector2f v;
    v.x = (enemy->sprite_.getPosition().x + enemy->dir.x * 32 * enemy->vit) - sprite_.getPosition().x;
    v.y = (enemy->sprite_.getPosition().y + enemy->dir.y * 32 * enemy->vit) - sprite_.getPosition().y;
    float norm = sqrt(v.x * v.x + v.y * v.y);
    v.x /= norm;
    v.y /= norm;
    sf::Vector2f v2;
    v2.x = sprite_.getPosition().x + 16;
    v2.y = sprite_.getPosition().y + 16;
    Bullet* b = new Bullet(BT_, v2, v);
    game.bullets.push_back(b);
}
