//
// Created by Bartek on 03.05.2019.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

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
enum GameState{FINISHED_LOOSE, RUNNING};
enum DIRECTION{UP,DOWN,LEFT,RIGHT};
class Snake {
    int width;
    int high;
    GameState gameState;
    int snakeLength;
    DIRECTION direction;
    std::vector  <snakeSegment> bodySnake;
    std::vector <sFoodPositions> foodPosition;
    int score;
    bool firstFood = true;
public:
    int getWidth() const{return width;}
    int getHigh() const{return high;}
    Snake(int width, int high);
    void randomFood();
    bool feedSnake();
    bool snakeCollision();
    void moveSnake();
    void snakePosition();
    void setDirection(DIRECTION direction1){direction=direction1;}
    DIRECTION getDirectiion()const{return direction;}
    const std::vector<snakeSegment> &getBodySnake() const{return bodySnake;};
    const std::vector<sFoodPositions> &getFoodPosition() const{return foodPosition;};
    std::string getScoreStr(){ std::string _str = std::to_string(score);return _str;}
    int getScore(){return score;}
    void crossWall();
    bool isFirstFood(){return firstFood;}
    GameState getGameState(){return gameState;}
    void snakeCollisionAnimation();
    void resetGameState(){gameState = RUNNING;}
    void resetScore(){score = 0;}
    void resetSnakeLenght(){snakeLength = 4;}
    void resetFirstFood(){firstFood = true;}
};


#endif //SNAKE_SNAKE_H
