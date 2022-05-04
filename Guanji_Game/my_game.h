#ifndef MY_GAME_H
#define MY_GAME_H

#include "../Game/Game.h"
#include <SFML/Graphics.hpp>
#include "blocks.h"
#include "system.h"
#include "../Game/Thumbnail.h"
#include <SFML/Audio.hpp>

class My_Game : public Game
{
public:
    My_Game();

    void load_music();
    void get_round();

    void load_background(sf::RenderTarget &window) const;

    void update(sf::RenderWindow &window);


    void start(sf::RenderWindow& window);
    void addEvents(sf::RenderWindow &window);
    void addEvents(const sf::RenderWindow &window, sf::Event& event);
    void draw(sf::RenderTarget &window, sf::RenderStates states) const;
   // void draw(sf::RenderWindow & window);
    void exit();

private:

    sf::Font font;
    sf::Texture t1;
    sf::Texture t2;
    sf::Texture t3;
    sf::Sprite background;
    sf::Sprite arr_pic;
    sf::Sprite Rule_pic;
    sf::RectangleShape grey_work_panel;

    sf::Text r_line_1;
    sf::Text r_line_2;
    sf::Text r_line_3;


    sf::SoundBuffer buffer;
    sf::Sound sound;


    int command;

    System system;

    sf::Sprite block[1000];

    GameText* logo;



};

#endif // MY_GAME_H
