#ifndef BLOCKS_H
#define BLOCKS_H

#include <iostream>
#include <SFML/Graphics.hpp>

struct Blocks
{
public:
    Blocks()
    {
        lives = 0;
    }

    Blocks(int round)
    {
        int rand = std::rand()%2+1;
        lives = rand* round;
        sf::RectangleShape(sf::Vector2f(50, 50));


    }


    sf::Color get_Color()
    {

        if(lives <= 20)
        {
            return sf::Color::Blue;
        }
        else if(lives <= 40)
        {
            return sf::Color::Red;
        }
        else if(lives <= 60)
        {
            return sf::Color::Yellow;
        }
        else if(lives <= 80)
        {
            return sf::Color::Cyan;
        }
        else if(lives >= 100)
        {
            return sf::Color::White;
        }

    }
    bool is_Alive(){return lives > 0 ;}


    int lives;

    bool alive;
};

#endif // BLOCKS_H
