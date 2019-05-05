//
// Created by Bartek on 03.05.2019.
//

#include "SnakeController.h"
#include <windows.h>

SnakeController::SnakeController(Snake &snake, SnakeView &snakeView, sf::RenderWindow &win):snake(snake),
snakeView(snakeView),
win(win)
{}
void SnakeController::controllEvent(sf::Event event) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if(snake.getDirectiion()!=UP) {
            snake.setDirection(DOWN);
            snake.moveDown();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if(snake.getDirectiion()!=LEFT) {
            snake.setDirection(RIGHT);
            snake.moveRight();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if(snake.getDirectiion()!=RIGHT) {
            snake.setDirection(LEFT);
            snake.moveLeft();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if(snake.getDirectiion()!=DOWN) {
            snake.setDirection(UP);
            snake.moveUp();
        }
    }
}
