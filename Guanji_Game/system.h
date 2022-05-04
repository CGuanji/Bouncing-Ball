#ifndef SYSTEM_H
#define SYSTEM_H


#include <vector>
#include <SFML/Graphics.hpp>
#include "blocks.h"
#include "round_manger.h"

using namespace std;
class System
{
public:
    System();
    void Step(int command);
    void Check();
    int Size();
    double getAngle();
//    void Draw(sf::RenderWindow& widnow) const;
    void Draw(sf::RenderTarget& widnow) const;



private:
//    vector<Particle> system;
    sf::RectangleShape _block[8][8];
    Blocks block[8][8];

    sf::CircleShape ball;
    sf::CircleShape tiny_ball;

    sf::Vector2f vel;

    int fix_vel;

    double angle;
    bool moving;
    bool round;
    bool game_over;




    Round_Manger manger;
};

#endif // SYSTEM_H
