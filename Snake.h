//
// Created by Bartek on 03.05.2019.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

struct snakeSegment{
    int xPos;
    int yPos;
};
struct sFoodPositions{
    int xFoodPos;
    int yFoodPos;
};
enum gameState{FINISHED_WIN, FINISHED_LOOSE, RUNNING};
enum DIRECTION{UP,DOWN,LEFT,RIGHT};
class Snake {
    int width;
    int high;
    gameState gameState;
    int snakeLength;
    DIRECTION direction;
    std::vector  <snakeSegment> bodySnake;
    std::vector <sFoodPositions> foodPosition;
    int score;
public:
    int getWidth() const{return width;}
    int getHigh() const{return high;}
    Snake(int width, int high);
    void randomFood();
    bool feedSnake();
    void moveSnake();
    void snakePosition();
    void setDirection(DIRECTION direction1){direction=direction1;}
    DIRECTION getDirectiion()const{return direction;}
    const std::vector<snakeSegment> &getBodySnake() const{return bodySnake;};
    const std::vector<sFoodPositions> &getFoodPosition() const{return foodPosition;};
    void setScore(){score = snakeLength;}
    int getScore(){ return score;}
};


#endif //SNAKE_SNAKE_H
