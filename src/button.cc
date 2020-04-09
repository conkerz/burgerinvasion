#include <iostream>
#include <fstream>
#include <string>
#include "includes/button.hh"

Button::Button(sf::Texture& texture, int x, int y)
    : MySprite(texture, x, y)
{
}

void Button::update_button(sf::RenderWindow& window)
{
    (void)window;
}

bool Button::ispressed(sf::RenderWindow& window)
{
    const sf::Vector2<int> pos = sf::Mouse::getPosition(window);
    int dx = pos.x - (sprite_.getPosition().x + 32);
    int dy = pos.y - (sprite_.getPosition().y + 32);
    float distance = sqrt(dx * dx + dy * dy);
    if (distance < 32)
        return true;
    return false;
}
