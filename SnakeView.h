//
// Created by Bartek on 03.05.2019.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include<string>
#include "Snake.h"

#ifndef SNAKE_SNAKEVIEW_H
#define SNAKE_SNAKEVIEW_H


class SnakeView {
Snake &snake;
int rectangleSize;
sf::Texture snakeImage;
sf::Texture appleImage;
sf::Texture bodyImage;
sf::Texture grassImage;
sf::Text textScore;
sf::Font font;
sf::Sprite head;
public:
    SnakeView(Snake &snake,int rectangleSize);
    void draw(sf::RenderWindow &window);
};


#endif //SNAKE_SNAKEVIEW_H
