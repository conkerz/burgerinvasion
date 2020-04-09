#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "includes/game-info.hh"
#include "includes/menu.hh"

static char *getmap(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "You must specify a map path!" << std::endl;
        exit(2);
    }
    return argv[1];
}

int main(int argc, char **argv)
{
    int width = WIDTH * TILE_WIDTH;
    int height = HEIGHT * TILE_HEIGHT + 75;
    sf::RenderWindow window(sf::VideoMode(width, height), "Burger Invasion");
    window.setMouseCursorVisible(false);

    // Init game 
    SpriteDB::load();
    GameInfo& game = GameInfo::getgame();
    game.map = new Matrix(getmap(argc, argv));
    game.initialize();
    Menu* menu = new Menu;
    menu->init_menu();

    // JUST TESTING
    game.current_state = MENU;

    sf::Clock clock; // Starting game time

    while (window.isOpen()) // Main loop
    {
      window.clear();
        sf::Time elapsed = clock.restart();
        if (game.current_state == MENU)
          {
            menu->update_menu(window);
            menu->draw_menu(window);
          }
        else if (game.current_state == PAUSE)
        {
          menu->update_menu(window);
          game.draw(window);
          menu->draw_pause(window);
        }
        else if (game.current_state == END)
        {
          menu->draw_end(window);
          menu->checkevents(window);
        }
        else
        {
          game.update(window, elapsed);
          game.draw(window);
        }
        window.display();
    }

    // Release ressources
    game.free();
    return 0;
}
