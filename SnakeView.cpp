//
// Created by Bartek on 03.05.2019.
//

#include "SnakeView.h"
#include "SFML/Graphics.hpp"

SnakeView::SnakeView(sf::RenderWindow &window, Snake &snake, int rectangleSize):snake(snake),
window(window)
{
    this->rectangleSize = rectangleSize;
}
void SnakeView::draw() {
    sf::RectangleShape rectangleShape(sf::Vector2f(rectangleSize,rectangleSize));
    for (int i = 0; i < snake.getHigh(); ++i) {
        for (int j = 0; j < snake.getWidth(); ++j) {
            rectangleShape.setPosition(i*rectangleSize, j*rectangleSize);
            rectangleShape.setFillColor(sf::Color::White);
            rectangleShape.setOutlineThickness(-1);
            rectangleShape.setOutlineColor(sf::Color::Black);
            if(snake.getPositionInfo(j,i)=='f')
                rectangleShape.setFillColor(sf::Color::Green);
            if(snake.getPositionInfo(j,i)=='h')
                rectangleShape.setFillColor(sf::Color::Red);
            if(snake.getPositionInfo(j,i)=='b')
                rectangleShape.setFillColor(sf::Color::Magenta);
            window.draw(rectangleShape);
        }
    }
}