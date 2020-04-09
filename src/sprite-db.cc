#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "includes/sprite-db.hh"

sf::Texture* SpriteDB::t_cursor = new sf::Texture;
sf::Texture* SpriteDB::t_cross = new sf::Texture;
sf::Texture* SpriteDB::t_square = new sf::Texture;

// Tiles
sf::Texture* SpriteDB::t_sand = new sf::Texture;
sf::Texture* SpriteDB::t_sand1 = new sf::Texture;
sf::Texture* SpriteDB::t_sand2 = new sf::Texture;
sf::Texture* SpriteDB::t_sand3 = new sf::Texture;
sf::Texture* SpriteDB::t_sand4 = new sf::Texture;
sf::Texture* SpriteDB::t_path = new sf::Texture;
sf::Texture* SpriteDB::t_arrivee = new sf::Texture;
sf::Texture* SpriteDB::t_begin = new sf::Texture;

// Bullets
sf::Texture* SpriteDB::t_bullet1 = new sf::Texture;
sf::Texture* SpriteDB::t_bullet2 = new sf::Texture;
sf::Texture* SpriteDB::t_bullet3 = new sf::Texture;

// Enemies
sf::Texture* SpriteDB::t_burgweak = new sf::Texture;
sf::Texture* SpriteDB::t_burgtank = new sf::Texture;
sf::Texture* SpriteDB::t_chipstank = new sf::Texture;
sf::Texture* SpriteDB::t_hotdog = new sf::Texture;
sf::Texture* SpriteDB::t_donut = new sf::Texture;
sf::Texture* SpriteDB::t_pika = new sf::Texture;

//Turrets
sf::Texture* SpriteDB::t_tows = new sf::Texture;
sf::Texture* SpriteDB::t_town = new sf::Texture;
sf::Texture* SpriteDB::t_towb = new sf::Texture;

// Hud
sf::Texture* SpriteDB::t_panel = new sf::Texture;

// Menu
sf::Texture* SpriteDB::t_menu_bg = new sf::Texture;
sf::Texture* SpriteDB::t_menu_pause = new sf::Texture;
sf::Texture* SpriteDB::t_menu_end = new sf::Texture;


void SpriteDB::load()
{
    t_cursor->loadFromFile("res/cursor.png");
    t_cross->loadFromFile("res/cross.png");
    t_square->loadFromFile("res/square.png");

    t_sand->loadFromFile("res/t_sand.png");
    t_sand1->loadFromFile("res/t_sand1.png");
    t_sand2->loadFromFile("res/t_sand2.png");
    t_sand3->loadFromFile("res/t_sand3.png");
    t_sand4->loadFromFile("res/t_sand4.png");
    t_path->loadFromFile("res/t_path.png");
    t_arrivee->loadFromFile("res/toilet.png");
    t_begin->loadFromFile("res/begin2.png");

    t_bullet1->loadFromFile("res/bullet1.png");
    t_bullet2->loadFromFile("res/bullet2.png");
    t_bullet3->loadFromFile("res/bullet3.png");

    t_burgweak->loadFromFile("res/weakburg.png");
    t_burgtank->loadFromFile("res/TANKBURGER.png");
    t_chipstank->loadFromFile("res/chips.png");
    t_hotdog->loadFromFile("res/hotdog.png");
    t_donut->loadFromFile("res/donut.png");
    t_pika->loadFromFile("res/pikashit.png");
    t_tows->loadFromFile("res/fastower.png");
    t_town->loadFromFile("res/tower.png");
    t_towb->loadFromFile("res/Vulcan_Sprite.png");

    t_panel->loadFromFile("res/panel.png");

    t_menu_bg->loadFromFile("res/burgerinvasion.png");
    t_menu_pause->loadFromFile("res/transparent.png");
    t_menu_end->loadFromFile("res/endgame.png");
}

void SpriteDB::unload()
{
    delete t_menu_bg;
    delete t_menu_pause;
    delete t_menu_end;
}
