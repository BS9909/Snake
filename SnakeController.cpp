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
            snake.moveSnake();
            if(snake.snakeCollision())
                finish = true;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if(snake.getDirectiion()!=LEFT) {
            snake.setDirection(RIGHT);
            snake.moveSnake();
            if(snake.snakeCollision())
                finish = true;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if(snake.getDirectiion()!=RIGHT) {
           snake.setDirection(LEFT);
           snake.moveSnake();
            if(snake.snakeCollision())
                finish = true;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if(snake.getDirectiion()!=DOWN) {
            snake.setDirection(UP);
            snake.moveSnake();
            if(snake.snakeCollision())
                finish = true;
        }
    }
}
