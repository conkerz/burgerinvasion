#ifndef MY_SPRITE_HH
# define MY_SPRITE_HH
# include <SFML/Graphics.hpp>

enum blocktype
{
    B_NONE = '\0',
    B_SAND = 's',
    B_PATH = 'p',
    B_BEGIN = 'b',
    B_END = 'e',
    B_NOPE = 127
};

class MySprite
{
    public:
        MySprite();
        MySprite(sf::Texture& texture);
        MySprite(sf::Texture& texture, int x, int y);
        void resize(float x, float y);
        virtual void update(sf::RenderWindow& window, sf::Time& time);
        virtual void draw(sf::RenderWindow& window);
        virtual ~MySprite() = default;

        static blocktype GetType(char c);
        static MySprite* GenerateSprite(char c, int x, int y);

        blocktype type;

        sf::Sprite sprite_;
};

#endif /* !MY_SPRITE_HH */
