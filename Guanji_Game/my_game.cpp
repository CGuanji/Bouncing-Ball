#include "my_game.h"

My_Game::My_Game()
{
    Game::title = " Ballz ";

    font.loadFromFile("OpenSans-Bold.ttf");
    cout<<"OpenSans-Bold.ttf loaded"<<endl;



    image_path = "ClutterMiku_750_1334.jpg";
    cout<<"ClutterMiku_750_1334.jpg loaded"<<endl;


    logo = new GameText(title, 100,sf::Vector2f(0,0));
    load_game();

    system = System();

    t1.loadFromFile(image_path);

    t2.loadFromFile("Arrow.jpg");
    t3.loadFromFile("Rules.png");
    cout<<"Arrow.jpg loaded"<<endl;
    cout<<"Rule.png loaded"<<endl;
    sf::Sprite b(t1);
    background = b;
    background.setScale(1.1,1.03);

    sf::Vector2f a(500,900);
    grey_work_panel.setFillColor(sf::Color(16,201,181));
    grey_work_panel.setPosition(825,0);
    grey_work_panel.setSize(a);


    sf::Sprite arr(t2);
    arr_pic = arr;
    arr_pic.setColor(sf::Color::Cyan);
    arr_pic.scale(0.1,0.1);
    arr_pic.setPosition(355,750);

    sf::Sprite rules(t3);
    Rule_pic = rules;
    Rule_pic.setPosition(850,200);
    Rule_pic.scale(0.5,0.5);

    r_line_1.setFont(font);
    r_line_1.setString("Press 'Space' to Lanuch the Ball");
    r_line_1.setFillColor(sf::Color::Red);
    r_line_1.setPosition(835,500);
    r_line_1.setCharacterSize(30);

    r_line_2.setFont(font);
    r_line_2.setString("'<-' 10 degree to the left");
    r_line_2.setFillColor(sf::Color::Black);
    r_line_2.setPosition(850,600);
    r_line_2.setCharacterSize(30);

    r_line_3.setFont(font);
    r_line_3.setString("'->' 10 degree to the right");
    r_line_3.setFillColor(sf::Color::Black);
    r_line_3.setPosition(850,650);
    r_line_3.setCharacterSize(30);

    buffer.loadFromFile("Kiki Delivery.ogg");

    cout<<"Kiki Delivery.ogg loaded"<<endl;

    sound.setBuffer(buffer);
    sound.play();


}

void My_Game::start(sf::RenderWindow & window)
{
    logo -> getText()->setPosition(window.getSize().x/2 - logo->getText()->getGlobalBounds().width/2,
                                    window.getSize().y/2 - logo->getText()->getGlobalBounds().height/2);

}

void My_Game::exit()
{

}


void My_Game::addEvents(sf::RenderWindow &window)
{

    update(window);

}

void My_Game::addEvents(const sf::RenderWindow &window, sf::Event& event)
{

       float mouseX, mouseY;

       switch (event.type)
       {
       // window closed

       // key pressed

       case sf::Event::KeyPressed:
           switch(event.key.code){
            case sf::Keyboard::Left:
               command = 2;
               break;
           case sf::Keyboard::Right:
               command = 3;
               break;
//           case sf::Keyboard::Escape:
//               sidebar[SB_KEY_PRESSED] = "ESC: EXIT";
//               window.close();
//            break;
           case sf::Keyboard::Space:
               command = 1;
               break;

           case sf::Keyboard::R:
                   command = 6;
               break;

           }

           break;

//           case sf::Keyboard::Escape:
//               sidebar[SB_KEY_PRESSED] = "ESC: EXIT";
//               window.close();
//            break;




//       case sf::Event::MouseEntered:
//           mouseIn = true;
//           break;

//       case sf::Event::MouseLeft:
//           mouseIn = false;
//           break;


           default:
               break;
       }


}
void My_Game::load_background(sf::RenderTarget &window) const
{
    window.draw(background);
    window.draw(arr_pic);
    window.draw(grey_work_panel);
    window.draw(Rule_pic);
    window.draw(r_line_1);
    window.draw(r_line_2);
    window.draw(r_line_3);



}
void My_Game::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    load_background(window);

    system.Draw(window);

}


void My_Game::update(sf::RenderWindow &window)
{

    system.Step(command);
    system.Check();
    command = 0;
    int rota = 180 + system.getAngle()*180/3.1415926;
    //cout<<rota<<endl;

    arr_pic.setRotation(rota);

}
