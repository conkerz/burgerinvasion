/**
** \file sprite-db.hh
** \brief
** \date December 2014
**
*/
#ifndef SPRITE_DB_HH
# define SPRITE_DB_HH

#include <SFML/Graphics.hpp>

class SpriteDB
{
    public:
        static void load();
        static void unload();

        static sf::Texture* t_cursor;
        static sf::Texture* t_cross;
        static sf::Texture* t_square;

        static sf::Texture* t_sand;
        static sf::Texture* t_sand1;
        static sf::Texture* t_sand2;
        static sf::Texture* t_sand3;
        static sf::Texture* t_sand4;
        static sf::Texture* t_path;
        static sf::Texture* t_arrivee;
        static sf::Texture* t_begin;

        static sf::Texture* t_bullet1;
        static sf::Texture* t_bullet2;
        static sf::Texture* t_bullet3;

        static sf::Texture* t_burgweak;
        static sf::Texture* t_burgtank;
        static sf::Texture* t_chipstank;
        static sf::Texture* t_hotdog;
        static sf::Texture* t_donut;
        static sf::Texture* t_pika;

        static sf::Texture* t_tows;
        static sf::Texture* t_town;
        static sf::Texture* t_towb;

        static sf::Texture* t_panel;

        static sf::Texture* t_menu_bg;
        static sf::Texture* t_menu_pause;
        static sf::Texture* t_menu_end;
};

#endif /* !SPRITE_DB_HH */
