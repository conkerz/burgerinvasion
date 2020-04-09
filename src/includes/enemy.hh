#ifndef ENEMY_HH
# define ENEMY_HH
# include "my-sprite.hh"
# include "moving-sprite.hh"
# include "sprite-db.hh"
# include <list>

enum enemytype
{
    WEAKBURG,
    TANKBURG,
    CHIPS,
    HOTDOG,
    DONUT,
    PIKA
};

class Enemy : public MovingSprite
{
    public:
        Enemy(enemytype type);
        //void is_hit(Tower& t);
        void setenemy(enemytype type);
        void update(sf::RenderWindow& window, sf::Time& time);
        void changepoint();
        void setdir();
        void getreckt(int damage);
        int length_life();
        void drawlife(sf::RenderWindow& window);

        // Pointer on destination point in path list
        std::list<std::pair<int,int>>::iterator dest;

        int nextx;
        int nexty;

        int gold;
        int hp;
        int hp_max;
};
#endif /* !ENEMY_HH */
