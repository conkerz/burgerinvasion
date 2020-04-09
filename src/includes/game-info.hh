/**
** \file game-info.hh
** \brief
** \date December 2014
**
*/
#ifndef GAME_INFO_HH
# define GAME_INFO_HH

# define WIDTH 24
# define HEIGHT 18
# define TILE_WIDTH 32
# define TILE_HEIGHT 32

# include "my-sprite.hh"
# include "moving-sprite.hh"
# include "matrix.hh"
# include "hud.hh"
# include "enemy.hh"
# include "stronkower.hh"
# include "fastower.hh"
# include "wave.hh"
# include "bullet.hh"

enum cursortype
{
    C_NORMAL,
    C_TSMALL,
    C_TMED,
    C_TBIG,
};

enum game_state
{
  MENU,
  PAUSE,
  RESUME,
  END
};

class GameInfo
{
    public:
        static GameInfo& getgame();
        ~GameInfo();
        void initialize();
        void update(sf::RenderWindow& window, sf::Time& elapsed);
        void checkevents(sf::RenderWindow& window);
        void draw(sf::RenderWindow& window);
        void free();
        void removeenemie(Enemy* e);
        void update_cursor(sf::RenderWindow& window);
        void spawn_tower(int x, int y);

        Matrix* map;

        int player_gold;
        int player_score;
        bool no_more_waves;

        std::list<Enemy*> enemies;
        std::list<Wave*> waves;
        std::list<Wave*>::iterator current_wave;
        std::list<Bullet*> bullets;
        std::list<Tower*> towers;
        sf::Font font;

        game_state current_state;

        Stronkower* tower;
        sf::Event event;

        MySprite* square;
        MySprite* cursor;
        cursortype ctype;

        MySprite* cursor_tsmall;
        MySprite* cursor_tmed;
        MySprite* cursor_tbig;
        MySprite* cursor_cross;
        MySprite* cursor_normal;
        bool draw_cross;
        bool win;

        Hud* panel_;

    private:
        GameInfo();
        GameInfo(GameInfo const&);
        void operator=(GameInfo const&);
        static GameInfo instance;
};

#endif /* !GAME_INFO_HH */
