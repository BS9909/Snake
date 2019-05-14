//
// Created by Bartek on 08.05.2019.
//

#include "GameManager.h"
#include <windows.h>

GameManager::GameManager(SnakeController &snakeController, ScoreController &scoreController):
snakeController(snakeController),
scoreController(scoreController)
{
    state = GAME;
}

void GameManager::updateState() {
    switch (state) {
        case GAME:
            if (snakeController.isFinished()) {
                state = SCORE;
            }
            break;
        case SCORE:
            if(snakeController.isFinished())
                state = GAME;

            break;
    }
}

void GameManager::handleEvent(sf::Event &event)
{
    updateState();
    switch (state) {
        case GAME:
            snakeController.controllEvent(event);
            break;
        case SCORE:
            scoreController.controllEvent(event);
            break;
    }
}

void GameManager::draw(sf::RenderWindow &win) {
    updateState();
    switch (state) {
        case GAME:
            snakeController.draw(win);
            break;
        case SCORE:
            scoreController.draw(win);
            break;
    }
}
