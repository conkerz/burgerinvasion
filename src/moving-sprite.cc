#include "includes/moving-sprite.hh"

MovingSprite::MovingSprite()
    : MySprite()
{
    vit = 1.0;
}

MovingSprite::MovingSprite(sf::Texture& t, sf::Vector2f pos, sf::Vector2f d)
    : MySprite(t)
    , dir(d)
{
    vit = 1.0;
    sprite_.setPosition(pos);
}

void MovingSprite::update(sf::RenderWindow& window, sf::Time& time)
{
    (void)window;
    (void)time;
    sf::Vector2f newpos(0, 0);
    newpos.x = sprite_.getPosition().x + dir.x * vit;
    newpos.y = sprite_.getPosition().y + dir.y * vit;
    sprite_.setPosition(newpos);
}
