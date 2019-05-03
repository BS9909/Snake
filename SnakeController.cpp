//
// Created by Bartek on 03.05.2019.
//

#include "SnakeController.h"

SnakeController::SnakeController(Snake &snake, SnakeView &snakeView, sf::RenderWindow &win):snake(snake),
snakeView(snakeView),
win(win)
{}
void SnakeController::controllEvent(sf::Event event) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            snake.moveDown();
            snakeView.draw();
    }
}
