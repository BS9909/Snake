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
    rowFoodPosition=0;
    columnFoodPosition=0;
    rowBodyPosition=0;
    columnBodyPosition=0;
    snakeLength = 3;
    gameState = RUNNING;
    for (int i = 0; i < high; ++i) {
        for (int j = 0; j < width; ++j) {
            board[i][j].food=false;
            board[i][j].head=false;
            board[i][j].body=false;
        }
    }
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
    if(rowFoodPosition==rowHeadPosition){
        rowFoodPosition = rand() % high;
        columnFoodPosition = rand() % width;
    }
    board[rowFoodPosition][columnFoodPosition].food = true;

}
void Snake::setHeadPosition() {
    for (int i = 0; i < snakeLength; ++i) {
        rowHeadPosition++;
        board[rowHeadPosition][columnHeadPosition].head = true;
        vec.push_back(board[rowHeadPosition][columnHeadPosition]);
    }
}
void Snake::snakeCollision() {
    for (int i = 0; i < high; ++i) {
        for (int j = 0; j < width; ++j) {
            if (board[i][j].food && board[i][j].head) {
                snakeLength++;
                while (rowFoodPosition == rowHeadPosition && columnHeadPosition == columnFoodPosition) {
                    rowFoodPosition = rand() % high;
                    columnFoodPosition = rand() % width;
                }
                board[rowFoodPosition][columnFoodPosition].food = true;
            }

            if(board[i][j].head && board[i][j].body) gameState = FINISHED_LOOSE;
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
        int oldRowPosition = rowHeadPosition;
        int oldColumnPosition = columnHeadPosition;
        board[oldRowPosition - snakeLength][oldColumnPosition].head = false;
        rowHeadPosition++;
        board[rowHeadPosition][oldColumnPosition].head = true;
        if (oldRowPosition - snakeLength > high-2) rowHeadPosition = -1;
        cout<<rowHeadPosition<<endl;
        Sleep(100);
}
void Snake::moveRight() {
    int oldRowPosition = rowHeadPosition;
    int oldColumnPosition = columnHeadPosition;
    board[oldRowPosition][oldColumnPosition-snakeLength].head = false;
    columnHeadPosition++;
    board[rowHeadPosition][columnHeadPosition].head = true;
    //przejscie przez sciane
    if (columnHeadPosition - snakeLength > width) columnHeadPosition = -1;
    Sleep(100);
}

const vector<sItem> &Snake::getVec() const {
    return vec;
}
