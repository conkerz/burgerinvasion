#ifndef TOWER_HH
# define TOWER_HH

# include "enemy.hh"
# include "my-sprite.hh"
# include "bullet.hh"


class Tower : public MySprite
{
    public:
        Tower(sf::Texture& text);
        Tower(sf::Texture& text, int dmg, int range, int speed);
        void update_tower();
        void set_type(enum bullettype i);
        bool is_in_range(Enemy& target);
        Enemy* get_target();
        void attack(Enemy* enemy);

    protected:
        int dmg_;
        float range_;
        int speed_;
        int max_speed_;
        bullettype BT_;
};

#endif /* !TOWER_HH */
