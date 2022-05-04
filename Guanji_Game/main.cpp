#include <iostream>
#include <SFML/Graphics.hpp>

#include "my_game.h"

using namespace sf;


int main(int argc, char *argv[])
{

    RenderWindow window(VideoMode(1300,800), " Ballz ");
    window.setFramerateLimit(60);
    My_Game my_Game;

    my_Game.start(window);
    while(window.isOpen())
    {
        sf::Event events;

        while(window.pollEvent(events))
        {

            if (events.type == sf::Event::Closed) {

                window.close();

            }
            my_Game.addEvents(window, events);
        }
        window.clear(sf::Color::White);
        my_Game.addEvents(window);

        window.draw(my_Game);
        window.display();

    }
}
