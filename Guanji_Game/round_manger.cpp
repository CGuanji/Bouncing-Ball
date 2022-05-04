#include "round_manger.h"

using namespace std;
Round_Manger::Round_Manger()
{
    win = true;
}

void Round_Manger::new_round(sf::RectangleShape (upgrade_blocks)[8][8])
{
    // sf::RectangleShape new_blocks[8][8];
     for(int i = 7;i >=0;i--)
     {
         for(int j =7; j >0 ;j--)
         {

           //  if(j!=0)
             {
                 upgrade_blocks[i][j].setScale(upgrade_blocks[i][j-1].getScale());

                 sf::Vector2f pos = upgrade_blocks[i][j-1].getPosition();

//                 if(j == 0 && i == 0)
//                 cout<<pos.x<<" "<<pos.y<<endl;

                 if(pos.x >= 0 && pos.y >=0)
                 upgrade_blocks[i][j].setPosition(pos.x,pos.y+100);
                 else
                 {
                     upgrade_blocks[i][j].setPosition(-10000000,-10000000);
                 }

                 sf::Color color = upgrade_blocks[i][j-1].getFillColor();
                 upgrade_blocks[i][j].setFillColor(color);

                 sf::Color c = upgrade_blocks[i][j-1].getOutlineColor();
                 upgrade_blocks[i][j].setOutlineColor(c);

                 upgrade_blocks[i][j].setOutlineThickness(upgrade_blocks[i][j-1].getOutlineThickness());

             }
 //            sf::Vector2f scale = upgrade_blocks[i][j].getScale();

     }
     }
//     cout<<"1lun: "<<endl;
//     for(int i = 0; i <8;i++)
//     {
//         for(int j = 0;j < 8;j++)
//         {
//             cout<< upgrade_blocks[j][i].getPosition().x<<","<<upgrade_blocks[j][i].getPosition().y<< "  ";
//            }
//         cout<<endl;
//     }

     Random r;

     int r_ = r.Next(0,255);
     int g_ = r.Next(0,255);
     int b_ = r.Next(0,255);

     for(int i = 0;i < 8;i++)
     {

         sf::Vector2f pos = upgrade_blocks[i][0].getPosition();
 //        if( i == 0)
 //        cout<<pos.x<<" "<<pos.y<<" | "<<endl;
 //        if( i == 1)
 //        cout<<pos.x<<" "<<pos.y<<" _ "<<endl;

         int r = std::rand()%2+1;
        // cout<<"rand: "<<r<<endl;
         if(r == 1)
         {
             upgrade_blocks[i][0].setFillColor(sf::Color(r_, g_, b_));
             upgrade_blocks[i][0].setPosition(i*100,0);

         }
         else
             upgrade_blocks[i][0].setPosition(-10000,-10000);
     }

//     cout<<"2lun: "<<endl;
//     for(int i = 0; i <8;i++)
//     {
//         for(int j = 0;j < 8;j++)
//         {
//             cout<< upgrade_blocks[j][i].getPosition().x<<","<<upgrade_blocks[j][i].getPosition().y<< "  ";
//            }
//         cout<<endl;
//     }

}

void Round_Manger::win_lose(sf::RectangleShape upgrade_blocks[8][8])
{

    for(int i = 0;i < 8;i++)
       {

           for(int j = 0;j < 8;j++)
           {
               if(i == 7 &&
                  upgrade_blocks[j][i].getPosition().x>=0 &&
                    upgrade_blocks[j][i].getPosition().y>=0)
               {
               //  cout<<upgrade_blocks[j][i].getPosition().x<<" , "<<upgrade_blocks[j][i].getPosition().y<<"  ";

                win = false;
               }
           }
          // cout<<endl;
       }

}

void Round_Manger::reset(sf::RectangleShape (upgrade_blocks)[8][8])
{
    for(int i = 0; i < 8;i++)
    {
        Random r;

        int r_ = r.Next(0,255);
        int g_ = r.Next(0,255);
        int b_ = r.Next(0,255);

        for(int j = 0; j < 8;j++)
        {

                upgrade_blocks[i][j] = sf::RectangleShape(sf::Vector2f(100,100));
                sf::Vector2f pos = upgrade_blocks[i][j].getPosition();
                  upgrade_blocks[i][j].setPosition(i*100,j*100);

                if(j==0)
                {
                    upgrade_blocks[i][j].setFillColor(sf::Color(r_, g_, b_));
                    //_block[i][j].setPosition(-1000,-1000);

                }
                if(i == 0 ||i == 7)
                {
                    upgrade_blocks[i][j].setPosition(-1000,-1000);

                }
                if(j == 1)
                {
                    upgrade_blocks[i][j].setFillColor(sf::Color(r_, g_, b_));;
                }
                if(j == 2)
                {
                    upgrade_blocks[i][j].setFillColor(sf::Color(r_, g_, b_));;

                }
                if(j >= 2)
                {
                    upgrade_blocks[i][j].setPosition(-1000,-1000);

                }

                upgrade_blocks[i][j].setOutlineColor(sf::Color::Black);
                upgrade_blocks[i][j].setOutlineThickness(2);
    }
    win = true;
    }

}
bool Round_Manger:: get_win()
{
    return win;
}

bool Round_Manger:: GG_flag()
{
    if(win == false)
    {
        return true;
    }

}
