//
// Created by user on 11.11.2021.
//

#ifndef SNAKE_SNAKEGAMEVISUALISER_H
#define SNAKE_SNAKEGAMEVISUALISER_H

#include "SnakeGame.h"
#include <SFML/Graphics.hpp>
#include <thread>

namespace sng {
    class SnakeGameVisualiser {
        using Vector2i = sng::Vector2<int>;
        using Vector2f = sng::Vector2<float>;

        SnakeGame &snakeGame;

        sf::RenderWindow window;
        sf::Clock clock;
        sf::Event eventHandler;

        sf::Color snakeColor = sf::Color::Green;
        sf::Color applesColor = sf::Color::Red;
        sf::Color backgroundColor{128, 128, 128};
        static constexpr Vector2f tileSize{10, 10};
    public:
        explicit SnakeGameVisualiser(SnakeGame &snakeGame, const std::string& windowName = "snake game");

        void run(float frameRate);
        void draw();
    };
}

#endif //SNAKE_SNAKEGAMEVISUALISER_H
