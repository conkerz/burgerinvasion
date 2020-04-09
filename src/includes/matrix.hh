#ifndef MATRIX_HH
# define MATRIX_HH

# include <vector>
# include <SFML/Graphics.hpp>
# include "my-sprite.hh"
# include <list>

class Matrix
{
  public :
    Matrix(const std::string& filename);
    void loadmap(std::ifstream&);
    void draw(sf::RenderWindow& window);
    int get_rows() const;
    int get_columns() const;
    MySprite* get_cel(int i, int j);
    blocktype get_type(int x, int y);
    void makepath();

    std::list<std::pair<int,int>> path;
    int spawnx;
    int spawny;

  protected :
    std::vector<std::vector<MySprite*>> data_;
    int rows_;
    int columns_;
};

#endif /* !MATRIX_HH */
