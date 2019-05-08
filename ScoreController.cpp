//
// Created by Bartek on 08.05.2019.
//

#include "ScoreController.h"

ScoreController::ScoreController(ScoreView &scoreView, Snake &snake,SnakeController &snakeController):scoreView(scoreView),
snake(snake),
snakeController(snakeController)
{}

void ScoreController::draw(sf::RenderWindow &window) {scoreView.draw(window);}

void ScoreController::controllEvent(sf::Event event) {
    auto mouse_position = sf::Mouse::getPosition(scoreView.getRenderWindow());
    auto translated_pos = scoreView.getRenderWindow().mapPixelToCoords(mouse_position);
    if (event.type == sf::Event::MouseButtonPressed){
        if (scoreView.getRecClose().getGlobalBounds().contains(translated_pos)){
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                scoreView.getRenderWindow().close();
        }
    }
    if (event.type == sf::Event::MouseButtonPressed){
        if (scoreView.getRecPlayAgain().getGlobalBounds().contains(translated_pos)){
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                finish = true;
                snake.resetFirstFood();
                snake.resetGameState();
                snake.resetScore();
                snake.resetSnakeLenght();
                snake.snakePosition();
                snake.randomFood();
                snakeController.resetFinish();
            }
        }
    }
}