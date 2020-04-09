/**
** \file button.hh
** \brief
** \date December 2014
**
*/
#ifndef BUTTON_HH
# define BUTTON_HH

# include <SFML/Graphics.hpp>
# include "my-sprite.hh"

class Button : public MySprite
{
    public:
        Button(sf::Texture& texture, int x, int y);
        void update_button(sf::RenderWindow& window);
        bool ispressed(sf::RenderWindow& window);
};

#endif /* !BUTTON_HH */
