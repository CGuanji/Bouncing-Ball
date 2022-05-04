#include "system.h"

#include <iostream>
#include <math.h>
#include <time.h>
#include "../../../CS3/Graphing/Graphing/random.h"
System::System()
{
    moving =false;
    round = false;
    game_over = false;
    int xpos = 100;
    int ypos = 100;

    fix_vel = 8;
    angle = 3.1415926/2;

    //the shape of the object, along with its velocity, acceleration,
    //position, etc. should be part of the individual object.z
    ball = sf::CircleShape(10);
    ball.setPosition(sf::Vector2f(349, 750));
    ball.setFillColor(sf::Color::Red);

    vel = sf::Vector2f(fix_vel*cos(angle),-fix_vel*sin(angle));


    //[列][行]

    int n = 0;
    for(int i = 0; i < 8;i++)
    {
        for(int j = 0; j < 8;j++)
        {
            {
                _block[i][j] = sf::RectangleShape(sf::Vector2f(100,100));
                sf::Vector2f pos = _block[i][j].getPosition();
                  _block[i][j].setPosition(i*100,j*100);

                if(j==0)
                {
                    _block[i][j].setFillColor(sf::Color::Green);
                    //_block[i][j].setPosition(-1000,-1000);

                }
                if(i == 0 ||i == 7)
                {
                    _block[i][j].setPosition(-1000,-1000);

                }
                if(j == 1)
                {
                    _block[i][j].setFillColor(sf::Color::Blue);
                }
                if(j == 2)
                {
                    _block[i][j].setFillColor(sf::Color::Cyan);

                }
//                if(j==3)
//                {
//                    _block[i][j].setFillColor(sf::Color::Yellow);

//                }
                if(j >= 2)
                {
                    _block[i][j].setPosition(-1000,-1000);

                }

                _block[i][j].setOutlineColor(sf::Color::Black);
                _block[i][j].setOutlineThickness(2);

            }
        }
    }


    manger = Round_Manger();






}


//------------------------------------------------------------------
//------------------------------------------------------------------
void System::Check()
{

    manger.win_lose(_block);
    if(!manger.get_win())
    {
        //manger.reset(_block);

    }
    game_over = manger.GG_flag();


}
void System::Step(int command)
{
    if(command ==1 )
    {
        moving = true;

    }
//    cout<<angle<<endl;


    if(command == 6)
    {
        manger.reset(_block);
        command = 0;
    }
    if(moving)
    {
        ball.move(vel.x,0);
      //  tiny_ball.move(vel.x,0);
        for(int i = 0; i < 8;i++)
        {
            for(int j = 0; j < 8;j++)
            {
                if(ball.getGlobalBounds().intersects(_block[i][j].getGlobalBounds()))
                {
                    _block[i][j].setPosition(-10000000000000,-10000000000000);
                    vel = sf::Vector2f(-1*vel.x,vel.y);
                }
            }
        }
        ball.move(0,vel.y);
      //  tiny_ball.move(0,vel.y);

        for(int i = 0; i < 8;i++)
        {
            for(int j = 0; j < 8;j++)
            {
                if(ball.getGlobalBounds().intersects(_block[i][j].getGlobalBounds()))
                {
                    _block[i][j].setPosition(-10000000000000,-10000000000000);
                    vel = sf::Vector2f(vel.x,-1*vel.y);
                }
            }

        }

            //all this is the responsibility of the
            // individual object:
         //   ball.move(vel);
            sf::Vector2f pos = ball.getPosition();
            if ((pos.x)>=800-20)
                vel = sf::Vector2f(-1*vel.x,1*vel.y);
            if (pos.x<=0)
                vel = sf::Vector2f(-1*vel.x,1*vel.y);
            if ((pos.y)>=800-20)
            {
               // vel = sf::Vector2f(1*vel.x,-1*vel.y);
                round = true;
                manger.new_round(_block);
                moving = false;

                ball.setPosition(349,750);

                vel = sf::Vector2f(-fix_vel*cos(angle),-fix_vel*sin(angle));

                command = 0;

            }
            if (pos.y<=0)
                vel = sf::Vector2f(1*vel.x,-1*vel.y);

    }
    else
    {
        if(command ==2)
        {

            angle-=3.1415926/18;
            if(angle >= 0)
            vel = sf::Vector2f(-fix_vel*cos(angle),-fix_vel*sin(angle));
            else
            {
                angle+=3.1415926/18;
            }
            command = 0;
        }
        if(command ==3)
        {
            angle+=3.1415926/18;
            if(angle >= 3.14)
            {
                angle-=3.1415926/18;

            }
            else
            {
                vel = sf::Vector2f(-fix_vel*cos(angle),-fix_vel*sin(angle));
            }

            command = 0;

        }

    }






}


void System::Draw(sf::RenderTarget &window) const
{
    if(!game_over)
    {
        //    window.clear();
            window.draw(ball);
           // window.draw(tiny_ball);
            //[列][行]

            for(int i = 0; i < 8;i++)
            {
                for(int j = 0; j < 8;j++)
                {
                   window.draw(_block[j][i]);
                }
            }
    }
    else
    {
        sf::Font a;
        sf::Text GG_Text;
        sf::Text Restart_Text;

        a.loadFromFile("OpenSans-Bold.ttf");
        GG_Text.setFont(a);
        GG_Text.setString("Game Over");
        GG_Text.setFillColor(sf::Color::Red);
        GG_Text.setPosition(270,300);
        GG_Text.setCharacterSize(60);

        Restart_Text.setFont(a);
        Restart_Text.setString("Restart Press R");
        Restart_Text.setFillColor(sf::Color::Red);
        Restart_Text.setPosition(270,500);
        Restart_Text.setCharacterSize(40);

        window.draw(GG_Text);
        window.draw(Restart_Text);

    }



}

double System:: getAngle()
{
    return angle;
}

