//
// Created by user on 11.11.2021.
//

#include "SnakeGameVisualiser.h"

sng::SnakeGameVisualiser::SnakeGameVisualiser(const SnakeGame &snakeGame, const std::string& _windowName) :
        snakeGame(snakeGame),
        window(sf::VideoMode(snakeGame.getMapSize().x * static_cast<int>(tileSize.x), snakeGame.getMapSize().y * static_cast<int>(tileSize.y)), _windowName)
{}

void sng::SnakeGameVisualiser::draw() {
    window.clear(backgroundColor);
    for(auto &s : snakeGame.getSnake()){
        sf::RectangleShape rectangleShape({tileSize.x, tileSize.y});
        rectangleShape.setFillColor(snakeColor);
        rectangleShape.setPosition({static_cast<float >(s.x), static_cast<float>(s.y)});
        window.draw(rectangleShape);
    }
    for(auto &a : snakeGame.getApples()){
        sf::RectangleShape rectangleShape({tileSize.x, tileSize.y});
        rectangleShape.setFillColor(applesColor);
        rectangleShape.setPosition({static_cast<float >(a.x), static_cast<float>(a.y)});
        window.draw(rectangleShape);
    }
    window.display();
}
