//
// Created by Bartek on 08.05.2019.
//

#include "ScoreView.h"
#include "Snake.h"
#include "SnakeController.h"

#ifndef SNAKE_SCORECONTROLLER_H
#define SNAKE_SCORECONTROLLER_H


class ScoreController {
    ScoreView &scoreView;
    Snake &snake;
    SnakeController &snakeController;
    bool finish = false;
public:
    ScoreController(ScoreView &scoreView, Snake &snake,SnakeController &snakeController);
    void draw(sf::RenderWindow &window);
    bool isFinished(){return finish;}
    void controllEvent(sf::Event event);
};


#endif //SNAKE_SCORECONTROLLER_H
