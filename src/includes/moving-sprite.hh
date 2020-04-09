#ifndef MOVING_SPRITE_HH
# define MOVING_SPRITE_HH
# include <SFML/Graphics.hpp>
# include "my-sprite.hh"

class MovingSprite : public MySprite
{
    public:
        MovingSprite();
        MovingSprite(sf::Texture& t, sf::Vector2f pos, sf::Vector2f dir);
        virtual void update(sf::RenderWindow& window, sf::Time& time) override;

        float vit;
        sf::Vector2f dir;
};

#endif /* !MOVING_SPRITE_HH */
