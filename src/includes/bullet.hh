/**
** \file bullet.hh
** \brief
** \date December 2014
**
*/
#ifndef BULLET_HH
# define BULLET_HH

# include "moving-sprite.hh"
# include "SFML/Graphics.hpp"
# include "enemy.hh"

enum bullettype
{
    B_SMALL,
    B_MEDIUM,
    B_BIG
};

class Bullet : public MovingSprite
{
    public:
        Bullet(bullettype t, sf::Vector2f pos, sf::Vector2f dir);
        void setbullet(bullettype type);
        bool updatebullet(sf::RenderWindow& window, sf::Time& time);
        bool collide(Enemy* e);

    protected:
        float rot_;
        float rotx_;
        int range_;
        int power_;
};

#endif /* !BULLET_HH */
