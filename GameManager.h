//
// Created by Bartek on 08.05.2019.
//
#include <SFML/Graphics.hpp>
#include "SnakeController.h"
#include "ScoreController.h"

#ifndef SNAKE_GAMEMANAGER_H
#define SNAKE_GAMEMANAGER_H


class GameManager {
    SnakeController &snakeController;
    ScoreController &scoreController;
    enum GameState {
        INTRO, GAME, SCORE
    } state;

private:
    void updateState();
public:
    GameManager(SnakeController &snakeController, ScoreController &scoreController);

    void draw(sf::RenderWindow &win);

    void handleEvent(sf::Event &event);
};


#endif //SNAKE_GAMEMANAGER_H
