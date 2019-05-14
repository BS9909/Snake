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
    sf::RectangleShape rectangleShapeFood(sf::Vector2f(rectangleSize, rectangleSize));
    sf::RectangleShape rectangleShapeBody(sf::Vector2f(rectangleSize, rectangleSize));
    sf::RectangleShape rectangleShapeHead(sf::Vector2f(rectangleSize, rectangleSize));
    sf::RectangleShape rectangleShapeFrame(sf::Vector2f(rectangleSize, rectangleSize));
    snake.moveSnake();
    //Funkcja odpowiedzialna za usuniecie ciała węża po jego kolizji
    if(snake.snakeCollision()) {
        snake.snakeCollisionAnimation();
        Sleep(1000);
    }
    //Utworzenie górnego paska na którym znajduje się aktualny score
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
    //funkcja odpowiedzialna za umiejscowienie pierwszego jedzenia, przed jakąkolwiek akcją węża.
    if(snake.isFirstFood()) {
        rectangleShapeFood.setTexture(&appleImage);
        rectangleShapeFood.setPosition(snake.getFoodPosition()[snake.getScore()].xFoodPos * rectangleSize,snake.getFoodPosition()[snake.getScore()].yFoodPos * rectangleSize);
        window.draw(rectangleShapeFood);

    }
    //funkcja odpowiedzialna za umiejscowienie jedzenia po zjedzeniu go przez węża.
    if(!snake.isFirstFood()) {
        rectangleShapeFood.setTexture(&appleImage);
        rectangleShapeFood.setPosition(snake.getFoodPosition()[snake.getScore()].xFoodPos * rectangleSize,snake.getFoodPosition()[snake.getScore()].yFoodPos * rectangleSize);
        window.draw(rectangleShapeFood);
    }
    //funkjca odpoweidzialna za narsowanie węża na ekranie.
    for (int i = 0; i < snake.getBodySnake().size(); ++i) {
        rectangleShapeBody.setPosition(snake.getBodySnake()[i].xPos*rectangleSize, snake.getBodySnake()[i].yPos*rectangleSize);
        rectangleShapeBody.setTexture(&bodyImage);
        window.draw(rectangleShapeBody);
        //warunek sprawdzający czy dany indeks vectora jest równy 0, jesli tak-oznacza ze jest to głowa
        //pozwala to na umiejscownienie odpowiedniej textruy jako pierwszej w ciele węża.
        if(i==0) {
            rectangleShapeHead.setPosition(snake.getBodySnake()[i].xPos*rectangleSize, snake.getBodySnake()[i].yPos*rectangleSize);
            rectangleShapeHead.setTexture(&snakeImage);
            window.draw(rectangleShapeHead);

        }
    }

}