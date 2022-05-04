#ifndef ABOUT_THIS_GAME_H
#define ABOUT_THIS_GAME_H
/*
  Youtube Link demonstration:      https://youtu.be/gqOPeokxVIY

There are a lot of challenges I experienced while I am coding this game.
 The most complex and un-understandable problems is when I save a "sf::rectangle shape [][]" 2-d array,
  I have to edit them all at once, and I don't get it why I cannot pick one row to edit it.
  Also, the [][] row/column pissed me off. I can not identify the row/col relations when I am doing the rectangle shape setting.
   It might sound easy, but I am still not sure the relations, and how to putting [i][j] into sfml.
    For example:: I am doing [4][j], this should indicating the 5th row, but it actually gives me 5th column!!!
     The screen coordinate for opposite y value also gives me a lot of trouble.
      When I trying to figure out the launching ball directions, I just can't figure it out well.
        The sfml is an amazing library, but the coordinate system just gave me a lot of troubles.

I self made this project. I referenced some of Professor Barkeshli's SFML sample code for bouncing ball.
    That helps me to do the initial bouncing ball purely just bouncing around on the screen.  And for the other part, I made them by myself.

I was thinking about doing it on Clion, but I have troubles to do Cmake files, and Cmake txt....  So I choose qt.  Sorry for that...

I added a background music, it is the main theme of "Kiki's Delivery"!
 Originally I was thinking to gave my blocks live, but If I going to do that, I would also increasing the amount of ball I create.
 It's not hard to do, but I just don't have more time to go beyond.
   The updating blocks costed me a long time to figure it out like I said on the top...
    The main concept is easy to copy the first row to the second row, and the second row to the third row and so on...
    And then create a random generated new now. It sounds easy, but.... It really got me..

Haha, enjoy!
Guanji Chen , Jun 9 at 10pm


  */
#endif // ABOUT_THIS_GAME_H
