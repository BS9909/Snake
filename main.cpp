#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "SnakeView.h"
#include "SnakeController.h"
#include "ScoreView.h"
#include "ScoreController.h"
#include "GameManager.h"

int main() {
    srand(time(NULL));
    sf::Event event;
    int recSize = 40;
    int row=20,column=20;
    //--------------------------------------------------------------------------//
    sf::RenderWindow window(sf::VideoMode(recSize*row,recSize*column), "Snake");
    Snake snake(row,column);
    SnakeView snakeView(snake, recSize);
    SnakeController snakeController(snake, snakeView,window);

    ScoreView scoreView(snake,window);
    ScoreController scoreController(scoreView, snake,snakeController);

    GameManager gameManager(snakeController, scoreController);

    while (window.isOpen()){
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            //snakeController.controllEvent(event);
            gameManager.handleEvent(event);
        }
        window.clear();

        //snakeView.draw(window);
        gameManager.draw(window);

        window.display();
    }

    return 0;

}