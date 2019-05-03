#include <iostream>
#include <conio.h>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "SnakeView.h"
#include "SnakeController.h"

int main() {
    srand(time(NULL));
    sf::Event event;
    int recSize = 40;
    int row=10,column=10;
    sf::RenderWindow window(sf::VideoMode(recSize*row,recSize*column), "Snake");
    Snake snake(row,column,0,0);
    SnakeView snakeView(window, snake, recSize);
    SnakeController snakeController(snake, snakeView,window);
    snake.setHeadPosition();
    snake.randomFood();
    snake.draw();
    while (window.isOpen()){
        while (window.pollEvent(event)) {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        snakeController.controllEvent(event);
        snakeView.draw();

        window.display();
    }

    return 0;

}