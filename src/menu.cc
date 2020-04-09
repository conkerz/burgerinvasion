#include "includes/menu.hh"
#include "includes/game-info.hh"
#include "includes/sprite-db.hh"
#include <iostream>


Menu::Menu()
  : play_(),
  exit_(),
  menu_background_(*SpriteDB::t_menu_bg, 0, 0),
  menu_pause_(*SpriteDB::t_menu_pause, 0, 0),
  menu_end_(*SpriteDB::t_menu_end, 0, 0)
{}

void Menu::init_menu()
{
  GameInfo& game = GameInfo::getgame();
  play_.setString("Play");
  play_.setFont(game.font);
  play_.setCharacterSize(40);
  play_.setColor(sf::Color::Black);
  play_.setOrigin(-32 * 9, -32 * 3);
  exit_.setString("Exit");
  exit_.setFont(game.font);
  exit_.setCharacterSize(40);
  exit_.setColor(sf::Color::Black);
  exit_.setOrigin(-32 * 11 - 16, -32 * 14 - 10);
  reset_.setString("Reset");
  reset_.setFont(game.font);
  reset_.setCharacterSize(40);
  reset_.setColor(sf::Color::Black);
  reset_.setOrigin(-32 * 14, -32 * 3);

  cursor = new MySprite(*SpriteDB::t_cursor);
  game.current_state = MENU;
}

void Menu::init_pause()
{
  GameInfo& game = GameInfo::getgame();
  playp_.setString("Play");
  playp_.setFont(game.font);
  playp_.setCharacterSize(40);
  playp_.setColor(sf::Color::Black);
  playp_.setOrigin(-32 * 9, -32 * 3);
  exitp_.setString("Exit");
  exitp_.setFont(game.font);
  exitp_.setCharacterSize(40);
  exitp_.setColor(sf::Color::Black);
  exitp_.setOrigin(-32 * 11 - 16, -32 * 14 - 10);
  reset_.setString("Reset");
  reset_.setFont(game.font);
  reset_.setCharacterSize(40);
  reset_.setColor(sf::Color::Black);
  reset_.setOrigin(-32 * 14, -32 * 3);

  cursor = new MySprite(*SpriteDB::t_cursor);
}

void Menu::update_menu(sf::RenderWindow& window)
{
    checkevents(window);
    update_cursor(window);
}

void Menu::draw_menu(sf::RenderWindow& window)
{
    checkevents(window);
    menu_background_.draw(window);
    window.draw(play_);
    window.draw(exit_);
    cursor->draw(window);

}

void Menu::update_cursor(sf::RenderWindow& window)
{
    const sf::Vector2<int> pos = sf::Mouse::getPosition(window);
    cursor->sprite_.setPosition(pos.x, pos.y);
}

void Menu::checkevents(sf::RenderWindow& window)
{
    GameInfo& game = GameInfo::getgame();
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (playClicked(window))
            {
                if (game.current_state == MENU)
                {
                    game.initialize();
                }
                game.current_state = RESUME;
            }
            else if (quitClicked(window))
            {
                if(game.current_state == MENU)
                    window.close();
                game.free();
                game.initialize();
                init_menu();
            }
            else if (game.current_state == PAUSE && resetClicked(window))
            {
                game.free();
                game.initialize();
                game.current_state = RESUME;
            }
        }
        if (!quitClicked(window))
        {
            if (game.current_state == MENU)
                exit_.setColor(sf::Color::Black);
            else
                exitp_.setColor(sf::Color::Black);
        }
        if (!playClicked(window))
        {
            if (game.current_state == MENU)
                play_.setColor(sf::Color::Black);
            else
                playp_.setColor(sf::Color::Black);
        }
        if (!resetClicked(window))
        {
            reset_.setColor(sf::Color::Black);
        }
    checkWhile();
    }
}

void Menu::checkWhile()
{
    GameInfo& game = GameInfo::getgame();
    if (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Return)
    {
        game.free();
        game.initialize();
        init_menu();
        game.current_state = MENU;
    }
}

bool Menu::playClicked(sf::RenderWindow& window)
{
    GameInfo& game = GameInfo::getgame();
    if (sf::Mouse::getPosition(window).x > 9 * 32 &&
      sf::Mouse::getPosition(window).y > 3 * 32 &&
      sf::Mouse::getPosition(window).x < 12 * 32 &&
      sf::Mouse::getPosition(window).y < 4 * 32)
    {
        if (game.current_state == MENU)
            play_.setColor(sf::Color::Red);
        else
            playp_.setColor(sf::Color::Red);
        return true;
    }
    return false;


}
bool Menu::quitClicked(sf::RenderWindow& window)
{
    GameInfo& game = GameInfo::getgame();
    if (sf::Mouse::getPosition(window).x > 11 * 32 + 16 &&
      sf::Mouse::getPosition(window).y > 14 * 32 + 10 &&
      sf::Mouse::getPosition(window).x < 14 * 32 &&
      sf::Mouse::getPosition(window).y < 15 * 32 + 16 )
    {
        if (game.current_state == MENU)
            exit_.setColor(sf::Color::Red);
        else
            exitp_.setColor(sf::Color::Red);
        return true;
    }
    return false;

}

bool Menu::resetClicked(sf::RenderWindow& window)
{
    if (sf::Mouse::getPosition(window).x > 14 * 32 &&
      sf::Mouse::getPosition(window).y > 3 * 32 + 10 &&
      sf::Mouse::getPosition(window).x < 17 * 32 &&
      sf::Mouse::getPosition(window).y < 4 * 32)
    {
        reset_.setColor(sf::Color::Red);
        return true;
    }
    return false;
}

void Menu::draw_pause(sf::RenderWindow& window)
{
  init_pause();
  checkevents(window);
  menu_pause_.draw(window);
  window.draw(playp_);
  window.draw(exitp_);
  window.draw(reset_);
  update_cursor(window);
  cursor->draw(window);
}

void Menu::draw_end(sf::RenderWindow& window)
{
  GameInfo& game = GameInfo::getgame();
  init_end();
  checkevents(window);
  menu_end_.draw(window);
  if (game.win)
    window.draw(win_msg_);
  else
    window.draw(lose_msg_);
}

void Menu::init_end()
{
  GameInfo& game = GameInfo::getgame();
  win_msg_.setString("Congratulations, you defeated \n the final boss!");
  win_msg_.setFont(game.font);
  win_msg_.setCharacterSize(30);
  win_msg_.setColor(sf::Color::White);
  win_msg_.setOrigin(-32 * 2, -32 * 6);
  lose_msg_.setString("Congratulations, you succeded...\n in hard failing!");
  lose_msg_.setFont(game.font);
  lose_msg_.setCharacterSize(50);
  lose_msg_.setColor(sf::Color::White);
  lose_msg_.setOrigin(-32 * 2, -32 * 6);
}
