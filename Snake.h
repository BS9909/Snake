//
// Created by Bartek on 03.05.2019.
//
#include <SFML/Graphics.hpp>
#include <vector>
#include <list>

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

struct sItem{
    bool head;
    bool food;
    bool body;
};
struct sPosition{
    int x,y;
};
enum gameState{FINISHED_WIN, FINISHED_LOOSE, RUNNING};
enum DIRECTION{UP,DOWN,LEFT,RIGHT};
class Snake {
    sItem board[100][100];
    sItem snakeBody[100];
    sPosition position;
    int width;
    int high;
    int rowFoodPosition;
    int columnFoodPosition;
    int moveCounter;
    int xOldPosition[100];
    int yOldPosition[100];
public:
    int getWidth() const;

    int getHigh() const;

private:
    int rowHeadPosition;
    int columnHeadPosition;
    int rowBodyPosition;
    int columnBodyPosition;
    int rectangleSize;
    gameState gameState;
    int snakeLength;
    DIRECTION direction;

public:
    Snake(int width, int high,int rowHeadPosition, int columnHeadPosition);
    void draw() const;
    void randomFood();
    void setHeadPosition();
    char getPositionInfo(int row, int column) const;
    void snakeCollision();
    void Feed();
    void moveDown();
    void moveRight();
    void moveLeft();
    void moveUp();
    void removeTail();
    void setSnake();
    void setDirection(DIRECTION direction1){direction=direction1;}
    DIRECTION getDirectiion()const{return direction;}
};


#endif //SNAKE_SNAKE_H
