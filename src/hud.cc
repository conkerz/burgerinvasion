#include "includes/hud.hh"
#include "includes/game-info.hh"

Hud::Hud(sf::Font& font, sf::Text& gold, sf::Text& score)
  : normal_tower_(*SpriteDB::t_towb, 32, 18 * 32 + 20),
  fast_tower_(*SpriteDB::t_tows, 3 * 32, 18 * 32 + 15),
  stronk_tower_(*SpriteDB::t_town, 6 * 32 - 15, 18 * 32 + 15),
  panel_(*SpriteDB::t_panel, 0, 18 * 32 + 5),
  font_(font),
  gold_(gold),
  score_(score),
  normal_price_(),
  fast_price_(),
  stronk_price_()
{}

void Hud::init_prices()
{
  GameInfo& game = GameInfo::getgame();
  normal_price_.setString("Price : 75$");
  normal_price_.setFont(game.font);
  normal_price_.setCharacterSize(15);
  normal_price_.setFillColor(sf::Color::Black);
  normal_price_.setOrigin(-32 + 16, -18 * 32 - 7);
  fast_price_.setString("Price : 150$");
  fast_price_.setFont(game.font);
  fast_price_.setCharacterSize(15);
  fast_price_.setFillColor(sf::Color::Black);
  fast_price_.setOrigin(-3 * 32 + 16, -18 * 32 - 7);
  stronk_price_.setString("Price : 305$");
  stronk_price_.setFont(game.font);
  stronk_price_.setCharacterSize(15);
  stronk_price_.setFillColor(sf::Color::Black);
  stronk_price_.setOrigin(-6 * 32 + 18, -18 * 32 - 7);
}

void Hud::print_hud(sf::RenderWindow& window)
{
  panel_.resize(2.05, 1);
  panel_.draw(window);
  normal_tower_.resize(0.5, 0.5);
  normal_tower_.draw(window);
  fast_tower_.resize(0.45, 0.45);
  fast_tower_.draw(window);
  stronk_tower_.draw(window);
  print_texts(window);
}

void Hud::print_texts(sf::RenderWindow& window)
{
  GameInfo& game = GameInfo::getgame();
  std::string str_gold = "Gold : " + std::to_string(game.player_gold);
  std::string str_score = "Score : " + std::to_string(game.player_score);
  gold_.setString(str_gold);
  score_.setString(str_score);
  window.draw(gold_);
  window.draw(normal_price_);
  window.draw(fast_price_);
  window.draw(stronk_price_);
  window.draw(score_);
}

sf::Font& Hud::get_font()
{
  return font_;
}
