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
public:
    SnakeController(Snake &snake, SnakeView &,sf::RenderWindow &win);
    void controllEvent(sf::Event event);
    void startGame();
};


#endif //SNAKE_SNAKECONTROLLER_H
