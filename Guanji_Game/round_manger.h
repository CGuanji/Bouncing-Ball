#ifndef ROUND_MANGER_H
#define ROUND_MANGER_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../../CS3/Graphing/Graphing/random.h"


class Round_Manger
{
public:
    Round_Manger();
    void new_round(sf::RectangleShape upgrade_blocks[8][8]);
    void win_lose(sf::RectangleShape upgrade_blocks[8][8]);
    void reset(sf::RectangleShape upgrade_blocks[8][8]);

    bool GG_flag();

    bool get_win();
private:
    bool win;
};

#endif // ROUND_MANGER_H
