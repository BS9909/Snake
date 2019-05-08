//
// Created by Bartek on 08.05.2019.
//

#include "ScoreView.h"

ScoreView::ScoreView(Snake &snake,sf::RenderWindow &renderWindow):snake(snake),
renderWindow(renderWindow)
{
    font.loadFromFile("arial.ttf");

    recPlayAgain.setPosition(125,300);
    recPlayAgain.setSize(sf::Vector2f(250,150));
    recPlayAgain.setFillColor(sf::Color::Green);
    recPlayAgain.setOutlineThickness(-2);
    recPlayAgain.setOutlineColor(sf::Color::Red);

    recClose.setPosition(400,300);
    recClose.setSize(sf::Vector2f(250,150));
    recClose.setFillColor(sf::Color::Red);
    recClose.setOutlineThickness(-2);
    recClose.setOutlineColor(sf::Color::Green);

    playAgainText.setFillColor(sf::Color::Black);
    playAgainText.setFont(font);
    playAgainText.setCharacterSize(50);
    playAgainText.setPosition(130,325);

    playAgainText.setString("Play again");

    closeText.setFillColor(sf::Color::Black);
    closeText.setFont(font);
    closeText.setCharacterSize(50);
    closeText.setPosition(460,325);
    closeText.setString("Close");

    scoreText.setFillColor(sf::Color::Red);
    scoreText.setFont(font);
    scoreText.setOutlineThickness(-1);
    scoreText.setOutlineColor(sf::Color::Green);
    scoreText.setCharacterSize(100);
    scoreText.setPosition(100,100);
    scoreText.setString("Your Score: " + snake.getScoreStr());

}

void ScoreView::draw(sf::RenderWindow &window) {
    window.draw(recPlayAgain);
    window.draw(recClose);
    window.draw(scoreText);
    window.draw(playAgainText);
    window.draw(closeText);
}

sf::RenderWindow &ScoreView::getRenderWindow() const {
    return renderWindow;
}

const sf::RectangleShape &ScoreView::getRecPlayAgain() const {
    return recPlayAgain;
}

const sf::RectangleShape &ScoreView::getRecClose() const {
    return recClose;
}
