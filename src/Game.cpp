#include "Game.h"


Game::Game(){
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "Snake");
    run();
}


Game::~Game()
    { delete window; }


void Game::draw(){
    // dispay number of points player got
    sf::Font font;
    if (!font.loadFromFile("../OpenSans-Italic.ttf"));    
    sf::Text text;
    text.setFont(font);
    text.setString("Points: " + std::to_string(points));
    text.setFillColor(sf::Color::Green);
    window->draw(text);

    // display board bounderies
    sf::RectangleShape rectangle1(sf::Vector2f( 8, 560 ));
    rectangle1.setPosition( 792, 40 );
    rectangle1.setFillColor(sf::Color::Red);
    window->draw(rectangle1);

    sf::RectangleShape rectangle2(sf::Vector2f( 8, 560 ));
    rectangle2.setPosition( 0, 40 );
    rectangle2.setFillColor(sf::Color::Red);
    window->draw(rectangle2);

    sf::RectangleShape rectangle3(sf::Vector2f( 800, 8 ));
    rectangle3.setPosition( 0, 40 );
    rectangle3.setFillColor(sf::Color::Red);
    window->draw(rectangle3);

    sf::RectangleShape rectangle4(sf::Vector2f( 800, 8 ));
    rectangle4.setPosition( 0, 592 );
    rectangle4.setFillColor(sf::Color::Red);
    window->draw(rectangle4);
}


void Game::run(){
    srand(time(NULL));

    // create snake
    Snake snake(400, 304);
    p[0] = rand()%( 784/8 )*8 + 8;
    p[1] = rand()%( 544/8 )*8 + 48;

    while(window->isOpen()){
        sf::Event event;
        while (window->pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window->close();
        }

        // clear and draw background
        window->clear(sf::Color::Black);
        draw();

        // draw snake
        for(unsigned i=0; i<snake.get_size(); i++){
            sf::RectangleShape rectangle(sf::Vector2f( 8, 8 ));
            rectangle.setPosition( snake[i].first, snake[i].second );
            rectangle.setFillColor(sf::Color::Green);
            window->draw(rectangle);
        }

        // draw a piece of food
        sf::RectangleShape point(sf::Vector2f( 8, 8 ));
        point.setPosition( p[0], p[1] );
        window->draw(point);

        // dispay all
        window->display();

        // check if key on keybord are pressed. If so => action
        // 'q' or 'escape' => quit game
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
            break;
        // 'down' => change direction to down
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            if(snake.get_direction() != 'u')
                snake.set_direction('d');
        }
        // 'up' => change direction to up
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            if(snake.get_direction() != 'd')
                snake.set_direction('u');
        }
        // 'left' => change direction to left
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            if(snake.get_direction() != 'r')
                snake.set_direction('l');
        }
        // 'right' => change direction to right
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            if(snake.get_direction() != 'l')
                snake.set_direction('r');
        }
        
        // check if its time for snake to move
        if(counter > limit/2){
            counter = 0;
            snake.change_pos();
        }

        // check if position where snake moves is allowed. If not restart the game
        for(unsigned i=1; i<snake.get_size(); i++){
            if( snake[0].first == snake[i].first && snake[0].second == snake[i].second ){
                points = 0;
                run();
                break;
            }
        }
        if( snake[0].first>=792 || snake[0].first<=0 || snake[0].second<=40 || snake[0].second>=592 ){
            points = 0;
            run();
            break;
        }

        // check if snakes position equals food position. If so, get points and generate new piece of food
        else if( p[0] == snake[0].first && p[1] == snake[0].second ){
            p[0] = rand()%( 784/8 )*8 + 8;
            p[1] = rand()%( 544/8 )*8 + 48;
            snake.add_element();
            points++;
            if(limit >= 20)
                limit--;
        }

        counter++;
    }
}
