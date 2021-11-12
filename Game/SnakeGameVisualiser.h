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
        sf::Color snakeColor = sf::Color::Green;
        sf::Color applesColor = sf::Color::Red;
        sf::Color backgroundColor = sf::Color(128, 128, 128);
        sf::Clock clock;
//        sf::Event eventHandler;

        const SnakeGame &snakeGame;
        sf::RenderWindow window;
        static constexpr Vector2f tileSize{10, 10};
    public:
        explicit SnakeGameVisualiser(const SnakeGame &snakeGame, const std::string& windowName = "snake game");

        /**
         * runs async
         */
        void run(float frameRate);
        void draw();
    };
}

#endif //SNAKE_SNAKEGAMEVISUALISER_H
