#ifndef HUD_HH
# define HUD_HH

# include <vector>
# include "my-sprite.hh"
# include "button.hh"
# include "sprite-db.hh"

class Hud
{
  public :
    Hud(sf::Font& font, sf::Text& gold, sf::Text& score);
    void init_prices();
    void print_hud(sf::RenderWindow& window);
    void print_texts(sf::RenderWindow& window);
    sf::Font& get_font();

    Button normal_tower_;
    Button fast_tower_;
    Button stronk_tower_;

  private :
    MySprite panel_;
    sf::Font font_;
    sf::Text gold_;
    sf::Text score_;
    sf::Text normal_price_;
    sf::Text fast_price_;
    sf::Text stronk_price_;

};

#endif /* !HUD_HH */
