//
// Created by Bartek on 03.05.2019.
//

#include "Snake.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <windows.h>

using namespace std;

Snake::Snake(int width, int high, int rowHeadPosition, int columnHeadPosition){
    this->width = width;
    this->high = high;
    this->rowHeadPosition = rowHeadPosition;
    this->columnHeadPosition = columnHeadPosition;
    position.x = 0;
    position.y = 0;
    rowFoodPosition=0;
    columnFoodPosition=0;
    rowBodyPosition=0;
    columnBodyPosition=0;
    snakeLength = 0;
    gameState = RUNNING;
    for (int i = 0; i < high; ++i) {
        for (int j = 0; j < width; ++j) {
            board[i][j].food=false;
            board[i][j].head=false;
            board[i][j].body=false;
        }
    }
    randomFood();

}
void Snake::draw() const {
    for (int i = 0; i < high; ++i) {
        for (int j = 0; j < width; ++j) {
            if (board[i][j].head) std::cout << "[H";
            else std::cout << "[.";
            if (board[i][j].food) std::cout << "f";
            else std::cout << ".";
            if (board[i][j].body) std::cout << "b]";
            else std::cout << ".]";
        }
        cout<<endl;
    }

}
void Snake::randomFood() {
    rowFoodPosition = rand() % high;
    columnFoodPosition = rand() % width;
    board[rowFoodPosition][columnFoodPosition].food = true;
}

void Snake::setHeadPosition() {
    if(direction==DOWN) {
        rowHeadPosition++;
        board[rowHeadPosition][columnHeadPosition].head = true;
        board[rowHeadPosition][columnHeadPosition].body = true;
        if (rowHeadPosition == high)
            rowHeadPosition = -1;
    }
    if(direction==RIGHT){
        columnHeadPosition++;
        board[rowHeadPosition][columnHeadPosition].head = true;
        board[rowHeadPosition][columnHeadPosition].body = true;
        if(columnHeadPosition == width)
            columnHeadPosition = -1;
    }
    if(direction==LEFT){
        columnHeadPosition--;
        board[rowHeadPosition][columnHeadPosition].head = true;
        board[rowHeadPosition][columnHeadPosition].body = true;
        if(columnHeadPosition == -1)
            columnHeadPosition = width;
    }
    if(direction==UP){
        rowHeadPosition--;
        board[rowHeadPosition][columnHeadPosition].head = true;
        board[rowHeadPosition][columnHeadPosition].body = true;
        if(rowHeadPosition == -1)
            rowHeadPosition = high;
    }

}

void Snake::snakeCollision() {
    for (int i = 0; i < high; ++i) {
        for (int j = 0; j < width; ++j) {
            if (board[i][j].food && board[i][j].head) {
                snakeLength++;
                board[rowFoodPosition][columnFoodPosition].food = false;
                randomFood();
                setSnake();
            }

            if(board[i][j].head && board[i][j].body) break;
        }
    }
}
char Snake::getPositionInfo(int row, int column) const {
    if(board[row][column].head && board[row][column].body) return 'x';
    if(board[row][column].food) return 'f';
    if(board[row][column].head) return 'h';
    if(board[row][column].body) return 'b';
}
int Snake::getWidth() const {
    return width;
}

int Snake::getHigh() const {
    return high;
}
void Snake::moveDown() {
    board[rowHeadPosition][columnHeadPosition].head = false;
    board[rowHeadPosition][rowHeadPosition].body = false;
    setHeadPosition();
    snakeCollision();
    Sleep(100);
}
void Snake::moveRight() {
    board[rowHeadPosition][columnHeadPosition].head = false;
    board[rowHeadPosition][columnHeadPosition].body = false;
    setHeadPosition();
    snakeCollision();
    Sleep(100);
}
void Snake::moveLeft() {
    board[rowHeadPosition][columnHeadPosition].head = false;
    board[rowHeadPosition][columnHeadPosition].body = false;
    setHeadPosition();
    snakeCollision();
    Sleep(100);
}
void Snake::moveUp() {
    board[rowHeadPosition][columnHeadPosition].head = false;
    board[rowHeadPosition][columnHeadPosition].body = false;
    setHeadPosition();
    snakeCollision();
    Sleep(100);
}
//Funkcja odpowiedzialna za odpowiednie ustawienie się nowego ciała snake
void Snake::setSnake() {
   // for (int i = 0; i < snakeLength; ++i) {
        if(direction == DOWN) {
            board[rowHeadPosition-snakeLength][columnHeadPosition].body = true;
            snakeBody[snakeLength] = board[rowHeadPosition-snakeLength][columnHeadPosition];
        }
        if(direction == UP) {
            board[rowHeadPosition+snakeLength][columnHeadPosition].body = true;
            snakeBody[snakeLength] = board[rowHeadPosition+snakeLength][columnHeadPosition];
        }
        if(direction == LEFT) {
            board[rowHeadPosition][columnHeadPosition+snakeLength].body = true;
            snakeBody[snakeLength] = board[rowHeadPosition][columnHeadPosition+snakeLength];
        }
        if(direction == RIGHT) {
            board[rowHeadPosition][columnHeadPosition-snakeLength].body = true;
            snakeBody[snakeLength] = board[rowHeadPosition][columnHeadPosition-snakeLength];
     //   }
    }
}

