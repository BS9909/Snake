//
// Created by Bartek on 08.05.2019.
//
#include "Snake.h"
#ifndef SNAKE_SCOREVIEW_H
#define SNAKE_SCOREVIEW_H


class ScoreView {
    Snake &snake;
    sf::Text scoreText;
    sf::Text playAgainText;
    sf::Text closeText;
    sf::Font font;
    sf::RectangleShape recPlayAgain;
    sf::RectangleShape recClose;
public:
    const sf::RectangleShape &getRecPlayAgain() const;

    const sf::RectangleShape &getRecClose() const;

private:
    sf::RenderWindow &renderWindow;
public:
    sf::RenderWindow &getRenderWindow() const;
    ScoreView(Snake &snake,sf::RenderWindow &renderWindow);
    void draw(sf::RenderWindow &window);
};


#endif //SNAKE_SCOREVIEW_H
