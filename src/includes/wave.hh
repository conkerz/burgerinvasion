/**
** \file wave.hh
** \brief
** \date December 2014
**
*/
#ifndef WAVE_HH
# define WAVE_HH

# include <SFML/Graphics.hpp>
# include <list>
# include "enemy.hh"

enum wavetype
{
    PRACTICE = 0,
    EASY = 1,
    MEDIUM = 2,
    HARD = 3,
    INSANE = 4,
    IMPOSSIBLE = 5,
    UMAD = 6
};

class Wave
{
    public:
        Wave();
        Wave(wavetype type);
        void update();

        bool finished;

        void setwave(wavetype type);

    private:
        std::list<Enemy*> mobs;

        void setwave_aux(wavetype type);

        int interval_;
        int counter_;
        int finishtime_;
        bool islast_;
};

#endif /* !WAVE_HH */
