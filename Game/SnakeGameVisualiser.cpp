//
// Created by user on 11.11.2021.
//

#include "SnakeGameVisualiser.h"
#include <iostream>

sng::SnakeGameVisualiser::SnakeGameVisualiser(SnakeGame &snakeGame, const std::string& _windowName) :
        snakeGame(snakeGame),
        window(sf::VideoMode(snakeGame.getMapSize().x * static_cast<int>(tileSize.x), snakeGame.getMapSize().y * static_cast<int>(tileSize.y)), _windowName),
        eventHandler()
{}

void sng::SnakeGameVisualiser::draw() {
    window.clear(backgroundColor);
    for (auto &s : snakeGame.getSnake()) {
        sf::RectangleShape rectangleShape({tileSize.x, tileSize.y});
        rectangleShape.setFillColor(snakeColor);
        rectangleShape.setPosition({static_cast<float>(s.x)*tileSize.x, static_cast<float>(s.y)*tileSize.y});
        window.draw(rectangleShape);
    }
    for (auto &a : snakeGame.getApples()) {
        sf::RectangleShape rectangleShape({tileSize.x, tileSize.y});
        rectangleShape.setFillColor(applesColor);
        rectangleShape.setPosition({static_cast<float>(a.x)*tileSize.x, static_cast<float>(a.y)*tileSize.y});
        window.draw(rectangleShape);
    }

    window.display();
}

void sng::SnakeGameVisualiser::run(float frameRate) {
    while (window.isOpen()){
        while(window.pollEvent(eventHandler))
            if(eventHandler.type == sf::Event::Closed){
                window.close();
                break;
            } else if(eventHandler.type == sf::Event::KeyPressed){
                switch (eventHandler.key.code) {
                    case sf::Keyboard::Up:
                        if(snakeGame.getDirection() != SnakeDirection::DOWN)
                            snakeGame.setDirection(SnakeDirection::UP);
                        break;
                    case sf::Keyboard::Right:
                        if(snakeGame.getDirection() != SnakeDirection::LEFT)
                            snakeGame.setDirection(SnakeDirection::RIGHT);
                        break;
                    case sf::Keyboard::Down:
                        if(snakeGame.getDirection() != SnakeDirection::UP)
                            snakeGame.setDirection(SnakeDirection::DOWN);
                        break;
                    case sf::Keyboard::Left:
                        if(snakeGame.getDirection() != SnakeDirection::RIGHT)
                            snakeGame.setDirection(SnakeDirection::LEFT);
                        break;
                    case sf::Keyboard::Escape:
                        window.close();
                        break;
                    default:
                        break;
                }
            }
        if(clock.getElapsedTime().asMilliseconds() >= 1000.f/frameRate) {
            if(snakeGame.getGameStatus() != GameStatus::LOST)
                snakeGame.incTimeStep();
            draw();
            clock.restart();
        }
    }
}
