#include "Snake.h"
#include <SFML/Window.hpp>
#include <iostream>
#include <time.h>
#include <string>

// class representing a game of snake.
class Game{

public:
    // constructor running 'run' function and creating a window
    Game();
    // destructor
    ~Game();

private:
    // window where game will apear
    sf::RenderWindow* window;
    // counter controling the speed of a snake
    unsigned counter = 0;
    // limit for a counter. Decreases everytime player gets a point
    unsigned limit = 70;
    // active piece of food coordinates
    unsigned p[2] = {600, 456};
    // number of points player got
    unsigned points = 0;

    // function that runs a game
    void run();
    // function that draws bounderies and number of points player got
    void draw();
};
