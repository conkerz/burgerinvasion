#ifndef MENU_HH
# define MENU_HH

# include <SFML/Graphics.hpp>
# include "my-sprite.hh"

class Menu
{
  public :
    Menu();
    void init_menu();
    void init_pause();
    void update_menu(sf::RenderWindow& window);
    void draw_menu(sf::RenderWindow& window);
    void checkevents(sf::RenderWindow& window);
    bool playClicked(sf::RenderWindow& window);
    bool quitClicked(sf::RenderWindow& window);
    bool resetClicked(sf::RenderWindow& window);
    void update_cursor(sf::RenderWindow& window);
    void checkWhile();
    void draw_end(sf::RenderWindow& window);
    void init_end();

    void draw_pause(sf::RenderWindow& window);

    sf::Event event;
    MySprite* cursor;

  private :
    sf::Text play_;
    sf::Text exit_;
    sf::Text reset_;
    sf::Text playp_;
    sf::Text exitp_;
    sf::Text resetp_;
    sf::Text win_msg_;
    sf::Text lose_msg_;


    MySprite menu_background_;
    MySprite menu_pause_;
    MySprite menu_end_;
};

#endif /* !MENU_HH */
