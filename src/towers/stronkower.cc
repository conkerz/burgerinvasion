#include "../includes/stronkower.hh"

Stronkower::Stronkower(sf::Texture& text)
    : Tower(text, 500, 32 * 5, 125)
{
    BT_ = B_BIG;
}
