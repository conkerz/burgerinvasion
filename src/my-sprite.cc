#include "includes/my-sprite.hh"
#include "includes/sprite-db.hh"
#include <cstdlib>

MySprite::MySprite()
    : sprite_()
{
}

MySprite::MySprite(sf::Texture& texture)
    : sprite_(texture)
{
}

MySprite::MySprite(sf::Texture& texture, int x, int y)
    : sprite_(texture)
{
    sprite_.setPosition(sf::Vector2f(x, y));
}

void MySprite::resize(float x, float y)
{
    sprite_.setScale(x, y);
}

void MySprite::update(sf::RenderWindow& window, sf::Time& time)
{
    (void)window;
    (void)time;
}

void MySprite::draw(sf::RenderWindow& window)
{
    window.draw(sprite_);
}

blocktype MySprite::GetType(char c)
{
    switch (c)
    {
    case 's':
        return B_SAND;
    case 'p':
        return B_PATH;
    case 'b':
        return B_BEGIN;
    case 'e':
        return B_END;
    case 127:
        return B_NOPE;
    }
    return B_NONE;
}

MySprite* MySprite::GenerateSprite(char c, int x, int y)
{
    sf::Texture* t;
    if (c == B_SAND)
    {
        int r = rand() % 50;
        if (r == 0)
            t = SpriteDB::t_sand1;
        else if (r == 1)
            t = SpriteDB::t_sand2;
        else if (r == 2)
            t = SpriteDB::t_sand3;
        else if (r == 3)
            t = SpriteDB::t_sand4;
        else
            t = SpriteDB::t_sand;
        if (r < 4)
            c = B_NOPE;
    }
    else if (c == B_PATH)
        t = SpriteDB::t_path;
    else if (c == B_BEGIN)
        t = SpriteDB::t_begin;
    else if (c == B_END)
        t = SpriteDB::t_arrivee;
    else
        t = SpriteDB::t_sand;

    MySprite* s = new MySprite(*t, x * 32, y * 32);
    s->type = MySprite::GetType(c);
    return s;
}
