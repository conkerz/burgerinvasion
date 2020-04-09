#include <iostream>
#include <fstream>
#include <string>
#include "includes/wave.hh"
#include "includes/game-info.hh"

Wave::Wave()
{
    counter_ = 0;
    finished = false;
    finishtime_ = 0;
}

Wave::Wave(wavetype type)
{
    counter_ = 0;
    finished = false;
    finishtime_ = 0;
    setwave(type);
}

void Wave::update()
{
    GameInfo& game = GameInfo::getgame();
    counter_++;
    if (counter_ >= interval_ && !finished)
    {
        if (mobs.size() <= 0)
            finished = true;
        else
        {
            Enemy* newmob = mobs.front();
            mobs.pop_front();
            game.enemies.push_front(newmob);
        }
        counter_ = 0;
    }
    if (finished)
    {
        if (finishtime_ >= 0)
            finishtime_--;
        if (finishtime_ <= 0 && game.enemies.size() <= 0)
        {
            if ((*game.current_wave)->islast_)
            {
                game.no_more_waves = true;
                game.win = true;
                game.current_state = END;
            }
            game.current_wave++;
        }
    }
}

void Wave::setwave(wavetype type)
{
    islast_ = false;
    if (type == PRACTICE)
    {
        interval_ = 150;
        finishtime_ = 10 * 60;
        mobs.push_back(new Enemy(WEAKBURG));
        mobs.push_back(new Enemy(WEAKBURG));
        mobs.push_back(new Enemy(WEAKBURG));
    }
    if (type == EASY)
    {
        interval_ = 120;
        finishtime_ = 10 * 60;
        mobs.push_back(new Enemy(WEAKBURG));
        mobs.push_back(new Enemy(WEAKBURG));
        mobs.push_back(new Enemy(TANKBURG));
    }
    if (type == MEDIUM)
    {
        interval_ = 90;
        finishtime_ = 8 * 60;
        mobs.push_back(new Enemy(WEAKBURG));
        mobs.push_back(new Enemy(TANKBURG));
        mobs.push_back(new Enemy(TANKBURG));
    }
    if (type == HARD)
    {
        interval_ = 140;
        finishtime_ = 8 * 60;
        mobs.push_back(new Enemy(WEAKBURG));
        mobs.push_back(new Enemy(TANKBURG));
        mobs.push_back(new Enemy(CHIPS));
    }
    setwave_aux(type);
}

void Wave::setwave_aux(wavetype type)
{
    if (type == INSANE)
    {
        interval_ = 120;
        finishtime_ = 5 * 60;
        mobs.push_back(new Enemy(TANKBURG));
        mobs.push_back(new Enemy(TANKBURG));
        mobs.push_back(new Enemy(HOTDOG));
        mobs.push_back(new Enemy(TANKBURG));
    }
    if (type == IMPOSSIBLE)
    {
        interval_ = 90;
        finishtime_ = 10 * 60;
        mobs.push_back(new Enemy(HOTDOG));
        mobs.push_back(new Enemy(DONUT));
        mobs.push_back(new Enemy(TANKBURG));
        mobs.push_back(new Enemy(CHIPS));
        mobs.push_back(new Enemy(CHIPS));
    }
    if (type == UMAD)
    {
        interval_ = 80;
        finishtime_ = 1 * 60;
        islast_ = true;
        mobs.push_back(new Enemy(HOTDOG));
        mobs.push_back(new Enemy(TANKBURG));
        mobs.push_back(new Enemy(CHIPS));
        mobs.push_back(new Enemy(CHIPS));
        mobs.push_back(new Enemy(CHIPS));
        mobs.push_back(new Enemy(CHIPS));
        mobs.push_back(new Enemy(CHIPS));
        mobs.push_back(new Enemy(CHIPS));
        mobs.push_back(new Enemy(CHIPS));
        mobs.push_back(new Enemy(CHIPS));
        mobs.push_back(new Enemy(HOTDOG));
        mobs.push_back(new Enemy(HOTDOG));
        mobs.push_back(new Enemy(HOTDOG));
        mobs.push_back(new Enemy(HOTDOG));
        mobs.push_back(new Enemy(HOTDOG));
        mobs.push_back(new Enemy(HOTDOG));
        mobs.push_back(new Enemy(HOTDOG));
        mobs.push_back(new Enemy(HOTDOG));
        mobs.push_back(new Enemy(TANKBURG));
        mobs.push_back(new Enemy(TANKBURG));
        mobs.push_back(new Enemy(TANKBURG));
        mobs.push_back(new Enemy(TANKBURG));
        mobs.push_back(new Enemy(TANKBURG));
        mobs.push_back(new Enemy(TANKBURG));
        mobs.push_back(new Enemy(TANKBURG));
        mobs.push_back(new Enemy(CHIPS));
        mobs.push_back(new Enemy(CHIPS));
        mobs.push_back(new Enemy(CHIPS));
        mobs.push_back(new Enemy(CHIPS));
        mobs.push_back(new Enemy(CHIPS));
        mobs.push_back(new Enemy(CHIPS));
        mobs.push_back(new Enemy(CHIPS));
        mobs.push_back(new Enemy(DONUT));
        mobs.push_back(new Enemy(DONUT));
        mobs.push_back(new Enemy(DONUT));
        mobs.push_back(new Enemy(DONUT));
        mobs.push_back(new Enemy(DONUT));
        mobs.push_back(new Enemy(DONUT));
        mobs.push_back(new Enemy(DONUT));
        mobs.push_back(new Enemy(PIKA));
        mobs.push_back(new Enemy(PIKA));
        mobs.push_back(new Enemy(PIKA));
        mobs.push_back(new Enemy(PIKA));
        mobs.push_back(new Enemy(PIKA));
    }
}
