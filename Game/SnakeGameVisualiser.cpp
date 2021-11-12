//
// Created by user on 11.11.2021.
//

#include "SnakeGameVisualiser.h"
#include <thread>
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
        rectangleShape.setPosition({static_cast<float >(s.x)*tileSize.x, static_cast<float>(s.y)*tileSize.y});
        window.draw(rectangleShape);
    }
    for (auto &a : snakeGame.getApples()) {
        sf::RectangleShape rectangleShape({tileSize.x, tileSize.y});
        rectangleShape.setFillColor(applesColor);
        rectangleShape.setPosition({static_cast<float >(a.x)*tileSize.x, static_cast<float>(a.y)*tileSize.y});
        window.draw(rectangleShape);
    }

    window.display();
}

void sng::SnakeGameVisualiser::run(float frameRate) {
    while (window.isOpen()){
        while(window.pollEvent(eventHandler))
            if(eventHandler.type == sf::Event::Closed){
                window.close();
                std::cout<<eventHandler.type<<"\n";
                break;
            }
        if(clock.getElapsedTime().asMilliseconds() >= 1000.f/frameRate) {
            snakeGame.incTimeStep();
            draw();
            clock.restart();
        }
    }
}
