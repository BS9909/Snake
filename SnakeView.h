//
// Created by Bartek on 03.05.2019.
//
#include <SFML/Graphics.hpp>
#include "Snake.h"

#ifndef SNAKE_SNAKEVIEW_H
#define SNAKE_SNAKEVIEW_H


class SnakeView {
sf::RenderWindow &window;
Snake &snake;
int rectangleSize;

public:
    SnakeView(sf::RenderWindow &window, Snake &snake,int rectangleSize);
    void draw();
};


#endif //SNAKE_SNAKEVIEW_H
