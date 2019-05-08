//
// Created by Bartek on 03.05.2019.
//
#include "Snake.h"
#include "SnakeView.h"

#ifndef SNAKE_SNAKECONTROLLER_H
#define SNAKE_SNAKECONTROLLER_H


class SnakeController {

    Snake &snake;
    SnakeView &snakeView;
    sf::RenderWindow &win;
    bool finish = false;
public:
    SnakeController(Snake &snake, SnakeView &,sf::RenderWindow &win);
    void controllEvent(sf::Event event);
    void startGame();
    bool isFinished(){return finish;}
    void draw(sf::RenderWindow & win){snakeView.draw(win);}
    void resetFinish(){finish = false;}

};


#endif //SNAKE_SNAKECONTROLLER_H
