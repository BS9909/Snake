//
// Created by Bartek on 03.05.2019.
//

#include "Snake.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <vector>
#include <windows.h>

using namespace std;

Snake::Snake(int width, int high) {
    this->width = width;
    this->high = high;
    snakeLength = 4;
    gameState = RUNNING;
    randomFood();
    snakePosition();
    score = 0;
}
void Snake::snakePosition() {
    for (int i = snakeLength; i > 0; --i) {
        bodySnake.push_back({0,i});
    }

}
void Snake::moveSnake() {
    Sleep(200-score*2);
    if(direction==DOWN ) {
        auto it = bodySnake.begin();
        bodySnake.insert(it, {bodySnake[0].xPos, bodySnake[0].yPos+1});
        //jesli snake nie zje jedzenia to usun ostatni element, jesli zje to nie usuwaj(automatycznie na ekranie
        //pojawi sie jeden segment więcej
        if(!feedSnake())
            bodySnake.pop_back();
        //jesli glowa snake znajdzie sie w pozycji w ktorej jest dowolny innny segment-ustaw gameState na FINISHED_LOOSE
        if(snakeCollision()) {
            gameState = FINISHED_LOOSE;

        }
        crossWall();
    }
    if(direction==RIGHT) {
        auto it = bodySnake.begin();
        bodySnake.insert(it, {bodySnake[0].xPos+1, bodySnake[0].yPos});
        if(!feedSnake())
            bodySnake.pop_back();
        if(snakeCollision()) {
            gameState = FINISHED_LOOSE;

        }
        crossWall();
    }
    if(direction==UP) {
        auto it = bodySnake.begin();
        bodySnake.insert(it, {bodySnake[0].xPos, bodySnake[0].yPos-1});
        if(!feedSnake())
            bodySnake.pop_back();
        if(snakeCollision()) {
            gameState = FINISHED_LOOSE;
        }
        crossWall();
    }
    if(direction==LEFT) {
        auto it = bodySnake.begin();
        bodySnake.insert(it, {bodySnake[0].xPos-1, bodySnake[0].yPos});
        if(!feedSnake())
            bodySnake.pop_back();
        if(snakeCollision()) {
            gameState = FINISHED_LOOSE;
        }
        crossWall();
    }
}
void Snake::randomFood() {
    int xFood;
    int yFood;
    for (int i = 0; i < high; ++i) {
        for (int j = 0; j <width; ++j) {
            do {
                int xFood = rand() % high;
                int yFood = rand() % width;
                foodPosition.push_back({xFood, yFood});
            } while (xFood == 0&& yFood && bodySnake[i].xPos == foodPosition[score].xFoodPos &&
                     bodySnake[j].yPos == foodPosition[score].yFoodPos);
        }
    }
}
bool Snake::feedSnake() {
    //Jesli pozycja glowy == pozycja jedzenia
    if(bodySnake[0].xPos == foodPosition[score].xFoodPos && bodySnake[0].yPos == foodPosition[score].yFoodPos) {
        firstFood = false;
        snakeLength++;
        score++;
        randomFood();
        return true;
    }
    return false;
}
void Snake::crossWall() {
    if(bodySnake[0].yPos == high)
        bodySnake[0].yPos = 1;

    if(bodySnake[0].yPos == 0)
        bodySnake[0].yPos = high;

    if(bodySnake[0].xPos == width)
        bodySnake[0].xPos = 0;

    if(bodySnake[0].xPos == -1)
        bodySnake[0].xPos = width;
}
bool Snake::snakeCollision() {
    //Jesli pozycja dowolnego indeksu vectora bodySnake == indeks zerowy tego vectora (głowa)
    //zwroc prawde
    for (int i = snakeLength; i > 0; --i) {
        if (bodySnake[0].xPos == bodySnake[i].xPos && bodySnake[0].yPos == bodySnake[i].yPos) {
            gameState = FINISHED_LOOSE;
            return true;
        }
    }
        return false;
}
void Snake::snakeCollisionAnimation() {
    for (int i = 0; i < snakeLength; ++i) {
        bodySnake.pop_back();
        Sleep(100);
    }
}
