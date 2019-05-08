//
// Created by Bartek on 03.05.2019.
//

#include "SnakeView.h"
#include <vector>
#include "SFML/Graphics.hpp"

SnakeView::SnakeView(sf::RenderWindow &window, Snake &snake, int rectangleSize):snake(snake),
window(window)
{
    this->rectangleSize = rectangleSize;
}
void SnakeView::draw() {
   // snake.moveSnake(); CZY TUTAJ TO MOZE BYĆ? (W CELU PORUSZANIA WEZA PO EKRANIE)
    sf::RectangleShape rectangleShape(sf::Vector2f(rectangleSize,rectangleSize));
    for (int i = 0; i < snake.getBodySnake().size(); ++i) {
        rectangleShape.setPosition(snake.getBodySnake()[i].xPos*rectangleSize, snake.getBodySnake()[i].yPos*rectangleSize);
        rectangleShape.setFillColor(sf::Color::Red);
    }
    if(snake.feedSnake()){
        rectangleShape.setPosition(snake.getFoodPosition()[0].xFoodPos*rectangleSize, snake.getFoodPosition()[0].yFoodPos*rectangleSize);
    }

}