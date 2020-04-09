#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "includes/game-info.hh"
#include "includes/sprite-db.hh"
#include "includes/enemy.hh"
#include "includes/menu.hh"

GameInfo GameInfo::instance = GameInfo();

GameInfo& GameInfo::getgame()
{
    return instance;
}

GameInfo::GameInfo()
{
    no_more_waves = false;
}

void GameInfo::initialize()
{
    player_gold = 300;
    player_score = 0;

    square = new MySprite(*SpriteDB::t_square);
    cursor_normal = new MySprite(*SpriteDB::t_cursor);
    cursor = cursor_normal;
    cursor_cross = new MySprite(*SpriteDB::t_cross);

    cursor_tsmall = new MySprite(*SpriteDB::t_towb);
    cursor_tsmall->sprite_.setOrigin(32-10, 32-5);
    cursor_tsmall->sprite_.setScale(0.40, 0.40);

    cursor_tmed = new MySprite(*SpriteDB::t_tows);
    cursor_tmed->sprite_.setOrigin(32, 64);
    cursor_tmed->sprite_.setScale(0.45, 0.45);

    cursor_tbig = new MySprite(*SpriteDB::t_town);
    cursor_tbig->sprite_.setOrigin(0, 32);
    cursor_tbig->sprite_.setScale(1, 1);

    ctype = C_NORMAL;

    waves.push_back(new Wave(PRACTICE));
    waves.push_back(new Wave(EASY));
    waves.push_back(new Wave(MEDIUM));
    waves.push_back(new Wave(HARD));
    waves.push_back(new Wave(INSANE));
    waves.push_back(new Wave(IMPOSSIBLE));
    waves.push_back(new Wave(UMAD));

    current_wave = waves.begin();

    font.loadFromFile("res/leadcoat.ttf");
    const std::string& str_gold = "Gold : " + std::to_string(player_gold);
    sf::Text gold(str_gold, font, 25);
    gold.setPosition(8 * 32, 18 * 32 + 8);
    gold.setColor(sf::Color::Black);
    const std::string& str_score = "Gold : " + std::to_string(player_score);
    sf::Text score(str_score, font, 25);
    score.setPosition(13 * 32, 18 * 32 + 8);
    score.setColor(sf::Color::Black);

    panel_ = new Hud(font, gold, score);
    panel_->init_prices();
}

void GameInfo::update(sf::RenderWindow& window, sf::Time& elapsed)
{
    // Processing events
    update_cursor(window);

    // Update entities
    if (!no_more_waves)
        (*current_wave)->update();
    for (Enemy* e : enemies)
        e->update(window, elapsed);
    Bullet* toremove = 0;
    for (Bullet* b : bullets)
    {
        bool remove = b->updatebullet(window, elapsed);
        if (remove)
            toremove = b;
    }
    for (Tower* t : towers)
        t->update_tower();
    if (toremove)
    {
        bullets.remove(toremove);
        delete toremove;
    }
}

void GameInfo::draw(sf::RenderWindow& window)
{
    // Draw entities
    map->draw(window);
    if (ctype == C_NORMAL)
        square->draw(window);
    panel_->print_hud(window);

    for (Bullet* b : bullets)
        b->draw(window);
    for (Enemy* e : enemies)
    {
        e->draw(window);
        e->drawlife(window);
    }
    for (Tower* t : towers)
        t->draw(window);

    cursor->draw(window);
    if (draw_cross)
        cursor_cross->draw(window);
}

void GameInfo::update_cursor(sf::RenderWindow& window)
{
    // Update cursor
    const sf::Vector2<int> pos = sf::Mouse::getPosition(window);
    int rx = (pos.x / 32) * 32;
    int ry = (pos.y / 32) * 32;
    blocktype hover = map->get_type(rx / 32, ry / 32);
    square->sprite_.setPosition(rx, ry);

    if (ctype != C_NORMAL)
        cursor->sprite_.setPosition(rx, ry);
    else
        cursor->sprite_.setPosition(pos.x, pos.y);
    cursor_cross->sprite_.setPosition(rx, ry);

    draw_cross = hover != B_SAND && ctype != C_NORMAL;

    // Check events
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                ctype = C_NORMAL;
                cursor = cursor_normal;
            }
            else
            {
                if (hover == B_SAND && ctype != C_NORMAL)
                    spawn_tower(rx, ry);
                if (panel_->normal_tower_.ispressed(window)) // Select l tower
                {
                    ctype = C_TSMALL;
                    cursor = cursor_tsmall;
                }
                if (panel_->fast_tower_.ispressed(window)) // Select um tower
                {
                    ctype = C_TMED;
                    cursor = cursor_tmed;
                }
                if (panel_->stronk_tower_.ispressed(window)) // Selt ig tower
                {
                    ctype = C_TBIG;
                    cursor = cursor_tbig;
                }
            }
        }
        if (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Escape)
           instance.current_state = PAUSE;
    }
}

void GameInfo::spawn_tower(int x, int y)
{
    int smallprice = 75;
    int medprice = 150;
    int bigprice = 305;
    if (ctype == C_TSMALL && player_gold >= smallprice)
    {
        Tower* t = new Tower(*SpriteDB::t_towb);
        t->sprite_.setPosition(x - 5, y - 10);
        towers.push_back(t);
        map->get_cel(y / 32, x / 32)->type = B_NONE;
        player_gold -= smallprice;
    }
    if (ctype == C_TMED && player_gold >= medprice)
    {
        Tower* t = new Fastower(*SpriteDB::t_tows);
        t->sprite_.setPosition(x - 10, y - 24);
        towers.push_back(t);
        map->get_cel(y / 32, x / 32)->type = B_NONE;
        player_gold -= medprice;
    }
    if (ctype == C_TBIG && player_gold >= bigprice)
    {
        Tower* t = new Stronkower(*SpriteDB::t_town);
        t->sprite_.setPosition(x, y - 28);
        towers.push_back(t);
        map->get_cel(y / 32, x / 32)->type = B_NONE;
        player_gold -= bigprice;
    }
}

void GameInfo::free()
{
    while (enemies.size() > 0)
    {
        Enemy* e = enemies.front();
        enemies.pop_front();
        delete e;
    }
    while (waves.size() > 0)
    {
        Wave* w = waves.front();
        waves.pop_front();
        delete w;
    }
    while (bullets.size() > 0)
    {
        Bullet* b = bullets.front();
        bullets.pop_front();
        delete b;
    }
    while (towers.size() > 0)
    {
        Tower* t = towers.front();
        towers.pop_front();
        delete t;
    }
}

GameInfo::~GameInfo()
{
    free();
    delete map;
    delete cursor;
    delete panel_;
    SpriteDB::unload();
}

void GameInfo::removeenemie(Enemy* e)
{
    enemies.remove(e);
    delete e;
}
