//
// Created by Bartek on 03.05.2019.
//
#include <SFML/Graphics.hpp>
#include <vector>

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

struct sItem{
    bool head;
    bool food;
    bool body;
};
enum gameState{FINISHED_WIN, FINISHED_LOOSE, RUNNING};
class Snake {
    sItem board[100][100];
    int width;
    int high;
    int rowFoodPosition;
    int columnFoodPosition;
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
public:
    Snake(int width, int high,int rowHeadPosition, int columnHeadPosition);
    void draw() const;
    void randomFood();
    void setHeadPosition();
    char getPositionInfo(int row, int column) const;
    void snakeCollision();
    void Feed();
    void moveDown();
};


#endif //SNAKE_SNAKE_H
