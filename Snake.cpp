//
// Created by Bartek on 03.05.2019.
//

#include "Snake.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <vector>

using namespace std;

Snake::Snake(int width, int high) {
    this->width = width;
    this->high = high;
    snakeLength = 4;
    gameState = RUNNING;
    randomFood();
    snakePosition();
}
void Snake::snakePosition() {
    for (int i = 0; i < snakeLength; ++i) {
        bodySnake[i].xPos = i;
        bodySnake[i].yPos = 0;
    }

}
//Poruszanie sie działa w następujący sposób, pozycja ostatniego indeksu vectora zamienia się z tym pierwszym
//Gdy wąż zje pokarm i metoda feedSnake zwróci wartość true to operacja zamiany się nie wykona a jedynie powstanie nowy element wektora o indeksie równym
//wartości snakeLength a jego pozcyja bedie równa pozycji snake +1
void Snake::moveSnake() {
    //Czy konieczny jest tu push_back czy takie cos jak w if else ponizej załatwi sprawę? problem mam w tym co dodac do tego push_backa, lub inaczej mówiąc
    //jak dostac sie do xPos i yPos w przypadku push_backa
    if(direction==DOWN && !feedSnake()){
        bodySnake[0].xPos = bodySnake[snakeLength].xPos;
        Sleep(500);
    }
    else if(direction==DOWN && feedSnake()){
        bodySnake[snakeLength].xPos = bodySnake[snakeLength-1].xPos;
    }

    if(direction==UP && !feedSnake()){
        bodySnake[snakeLength].xPos = bodySnake[0].xPos;
        Sleep(500);
    }
    else if(direction==UP && feedSnake()){
        bodySnake[snakeLength].xPos = bodySnake[snakeLength+1].xPos;
    }

    if(direction==RIGHT && !feedSnake()){
        bodySnake[0].yPos = bodySnake[snakeLength].yPos;
        Sleep(500);
    }
    else if(direction==RIGHT && feedSnake()){
        bodySnake[snakeLength].yPos = bodySnake[snakeLength+1].yPos;
    }

    if(direction==LEFT && !feedSnake()){
        bodySnake[snakeLength].yPos = bodySnake[0].yPos;
        Sleep(500);
    }
    else if(direction==RIGHT && feedSnake()){
        bodySnake[snakeLength].yPos = bodySnake[snakeLength-1].yPos;
    }
}
//Losowanie jedzenia DORÓB KONIECZNIE WARUNEK W KTORYM SPRAWDZASZ CZY NIE WYLOSOWANO JEDZENIA W MIEJSCE W KTÓRYM ZNAJDUJE SIĘ CIAŁO SNAKE!!!
void Snake::randomFood() {
    foodPosition[0].yFoodPos = rand() % high;
    foodPosition[0].xFoodPos = rand() % width;
}
bool Snake::feedSnake() {
    if(bodySnake[snakeLength].xPos == foodPosition[0].xFoodPos && bodySnake[snakeLength].yPos == foodPosition[0].yFoodPos) {
        randomFood();
        snakeLength++;
        setScore();
        return true;
    }
    return false;
}

