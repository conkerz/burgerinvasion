#include <fstream>
#include <iostream>
#include <istream>
#include <cstring>
#include "includes/matrix.hh"
#include "includes/my-sprite.hh"

Matrix::Matrix(const std::string& filename)
{
  std::ifstream map(filename);
  std::string str;
  if (!map.is_open())
  {
    std::cerr << "Cannot open map file " << filename << std::endl;
    std::exit(1);
  }
  else
  {
    map >> str;
    columns_ = str.size();
    rows_ = 1;
    while (map >> str)
      ++rows_;
    if (rows_ != 18 || columns_ != 24)
    {
      std::cerr << "Invalid map size, it must be 18 rows by 24 columns"
        << std::endl;
      std::exit(2);
    }
    data_.resize(rows_);
    for (int i = 0; i < rows_; ++i)
    {
      data_[i].resize(columns_);
    }
  }
  map.close();
  std::ifstream fesse(filename);
  loadmap(fesse);
}

void Matrix::loadmap(std::ifstream& map)
{
  spawnx = 0;
  spawny = 0;
  char c;
  for (int i = 0; i < rows_; ++i)
  {
    for (int  j = 0; j < columns_ + 1; ++j)
    {
      c = map.get();
      if (c != '\n')
        data_[i][j] = MySprite::GenerateSprite(c, j, i);
      if (c == 'b')
      {
          spawnx = j;
          spawny = i;
      }
    }
  }
  makepath();
}

void Matrix::draw(sf::RenderWindow& window)
{
  for (int i = 0; i < rows_; ++i)
  {
    for (int j = 0; j < columns_; ++j)
    {
      data_[i][j]->draw(window);
    }
  }
}

int Matrix::get_rows() const
{
  return rows_;
}

int Matrix::get_columns() const
{
  return columns_;
}

MySprite* Matrix::get_cel(int i, int j)
{
  return data_[i][j];
}

// Get type of block at x,y avoiding segfaults
blocktype Matrix::get_type(int x, int y)
{
    if (x < 0 || x >= 24 || y < 0 || y >= 18)
        return B_NONE;
    if (x == spawnx && y == spawny)
        return B_NONE;
    blocktype t = get_cel(y, x)->type;
    return t == B_END ? B_PATH : t;
}

void Matrix::makepath()
{
    int x = spawnx;
    int y = spawny;

    if (get_type(x + 1, y) == B_PATH)
        x = x + 1;
    else if (get_type(x, y + 1) == B_PATH)
        y = y + 1;
    else if (get_type(x - 1, y) == B_PATH)
        x = x - 1;
    else if (get_type(x, y - 1) == B_PATH)
        y = y - 1;
    else
    {
        std::cout << "Invalid map: no path joining spawn." << std::endl;
        exit(2);
    }
    // Pushing first point after spawn
    path.push_back(std::pair<int, int>(x, y));

    int prevx;
    int prevy;
    while (1)
    {
        int oldx = x;
        int oldy = y;

        if (get_type(x + 1, y) == B_PATH && x + 1 != prevx)
            x = x + 1;
        else if (get_type(x, y + 1) == B_PATH && y + 1 != prevy)
            y = y + 1;
        else if (get_type(x - 1, y) == B_PATH && x - 1 != prevx)
            x = x - 1;
        else if (get_type(x, y - 1) == B_PATH && y - 1 != prevy)
            y = y - 1;
        else
            break;

        prevx = oldx;
        prevy = oldy;

        path.push_back(std::pair<int, int>(x, y));
    }
}
