#include "../includes/enemy.hh"
#include <cmath>
#include "../includes/game-info.hh"
#include <iostream>

Enemy::Enemy(enemytype type)
    : MovingSprite()
{
    setenemy(type);
    GameInfo& game = GameInfo::getgame();
    dest = game.map->path.begin();
    nextx = std::get<0>(*dest);
    nexty = std::get<1>(*dest);
}

void Enemy::setenemy(enemytype type)
{
    GameInfo& game = GameInfo::getgame();
    int startx = game.map->spawnx * 32;
    int starty = game.map->spawny * 32;
    sprite_.setPosition(sf::Vector2f(startx, starty));
    dir = sf::Vector2f(1, 0);
    if (type == WEAKBURG)
    {
        sprite_.setTexture(*SpriteDB::t_burgweak, true);
        resize(0.4, 0.4);
        vit = 1;
        hp = 100;
        gold = 10;
    }
    if (type == TANKBURG)
    {
        sprite_.setTexture(*SpriteDB::t_burgtank, true);
        resize(0.45, 0.45);
        vit = 0.9;
        hp = 300;
        gold = 25;
    }
    if (type == CHIPS)
    {
        sprite_.setTexture(*SpriteDB::t_chipstank, true);
        vit = 1.05;
        hp = 200;
        gold = 35;
    }
    if (type == HOTDOG)
    {
        sprite_.setTexture(*SpriteDB::t_hotdog, true);
        vit = 1.05;
        hp = 300;
        gold = 60;
    }
    if (type == DONUT)
    {
        sprite_.setTexture(*SpriteDB::t_donut, true);
        vit = 1.15;
        hp = 500;
        gold = 85;
    }
    if (type == PIKA)
    {
        sprite_.setTexture(*SpriteDB::t_pika, true);
        resize(0.25, 0.25);
        vit = 1.15;
        hp = 1000;
        gold = 10000000;
    }
    hp_max = hp;
}

void Enemy::update(sf::RenderWindow& window, sf::Time& time)
{
    MovingSprite::update(window, time);

    // Set direction to point and change destination if needed
    setdir();
}

void Enemy::changepoint()
{
    dest++;
    GameInfo& game = GameInfo::getgame();
    if (dest == game.map->path.end())
    {
        game.win = false;
        game.current_state = END;
    }
    else
    {
        nextx = std::get<0>(*dest);
        nexty = std::get<1>(*dest);
    }
}

void Enemy::setdir()
{
    float x = sprite_.getPosition().x;
    float y = sprite_.getPosition().y;
    float dx = (nextx ) * 32 - x;
    float dy = (nexty ) * 32 - y;
    float distance = sqrt(dx * dx + dy * dy);
    dx = dx / distance;
    dy = dy / distance;
    dir = sf::Vector2f(dx, dy);

    // Test if mob reached the point
    if (distance < 10)
        changepoint();
}

void Enemy::getreckt(int damage)
{
    hp -= damage;
}

int Enemy::length_life()
{
    return (32 * hp) / hp_max;
}

void Enemy::drawlife(sf::RenderWindow& window)
{
    sf::Color n(0, 0, 0);
    sf::RectangleShape red(sf::Vector2f(32, 4));
    red.setFillColor(sf::Color(255, 0, 0));
    red.setOutlineColor(n);
    sf::RectangleShape green(sf::Vector2f(length_life(), 4));
    green.setFillColor(sf::Color(0, 255, 0));
    green.setOutlineColor(n);
    red.setPosition(sprite_.getPosition().x, sprite_.getPosition().y - 10);
    green.setPosition(sprite_.getPosition().x, sprite_.getPosition().y - 10);
    window.draw(red);
    window.draw(green);
}
