#include "../includes/fastower.hh"

Fastower::Fastower(sf::Texture& text)
    : Tower(text, 20, 32 * 4.5, 20)
{
    resize(0.40, 0.40);
    BT_ = B_SMALL;
}
