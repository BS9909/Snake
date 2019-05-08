//
// Created by Bartek on 03.05.2019.
//

#include "SnakeView.h"
#include <windows.h>
#include <vector>
#include "SFML/Graphics.hpp"

SnakeView::SnakeView(Snake &snake, int rectangleSize):snake(snake)
{
    this->rectangleSize = rectangleSize;
    appleImage.loadFromFile("apple.jpg");
    snakeImage.loadFromFile("head.jpg");
    bodyImage.loadFromFile("body.jpg");
    grassImage.loadFromFile("grass.jpg");
    font.loadFromFile("arial.ttf");
}
void SnakeView::draw(sf::RenderWindow &window) {
    snake.moveSnake();
    if(snake.snakeCollision()) {
        snake.snakeCollisionAnimation();
        Sleep(1000);
    }
    Sleep(100);
    sf::RectangleShape rectangleShapeFood(sf::Vector2f(rectangleSize, rectangleSize));
    sf::RectangleShape rectangleShapeBody(sf::Vector2f(rectangleSize, rectangleSize));
    sf::RectangleShape rectangleShapeHead(sf::Vector2f(rectangleSize, rectangleSize));
    sf::RectangleShape rectangleShapeFrame(sf::Vector2f(rectangleSize, rectangleSize));

    for (int j = 0; j < snake.getWidth(); ++j) {
        rectangleShapeFrame.setPosition(j*rectangleSize,0);
        rectangleShapeFrame.setTexture(&grassImage);
        window.draw(rectangleShapeFrame);
    }
    textScore.setFont(font);
    textScore.setPosition(0,0);
    textScore.setFillColor(sf::Color::Black);
    textScore.setOutlineThickness(-1);
    textScore.setOutlineColor(sf::Color::Red);
    textScore.setCharacterSize(40);
    textScore.setString("Score: "+ snake.getScoreStr());
    window.draw(textScore);

    if(snake.isFirstFood()) {
        rectangleShapeFood.setTexture(&appleImage);
        rectangleShapeFood.setPosition(snake.getFoodPosition()[snake.getScore()].xFoodPos * rectangleSize,snake.getFoodPosition()[snake.getScore()].yFoodPos * rectangleSize);
        window.draw(rectangleShapeFood);

    }
    if(!snake.isFirstFood()) {
        rectangleShapeFood.setTexture(&appleImage);
        rectangleShapeFood.setPosition(snake.getFoodPosition()[snake.getScore()].xFoodPos * rectangleSize,snake.getFoodPosition()[snake.getScore()].yFoodPos * rectangleSize);
        window.draw(rectangleShapeFood);
    }
    for (int i = 0; i < snake.getBodySnake().size(); ++i) {
        rectangleShapeBody.setPosition(snake.getBodySnake()[i].xPos*rectangleSize, snake.getBodySnake()[i].yPos*rectangleSize);
        rectangleShapeBody.setTexture(&bodyImage);
        window.draw(rectangleShapeBody);
        if(i==0) {
            rectangleShapeHead.setPosition(snake.getBodySnake()[i].xPos*rectangleSize, snake.getBodySnake()[i].yPos*rectangleSize);
            rectangleShapeHead.setTexture(&snakeImage);
            window.draw(rectangleShapeHead);

        }
    }


}