//
// Created by user on 11.11.2021.
//

#ifndef SNAKE_SNAKEGAME_H
#define SNAKE_SNAKEGAME_H
#include <vector>
#include <deque>
#include <unordered_set>
#include "Utils.h"

namespace sng {
    class SnakeGame {
        using Vector2i = sng::Utils::Vector2<int>;
        Vector2i mapSize;
        /**
         * 0 - up, 1 - right, 2 - down, 3 - left
         */
        int direction = 0;
        bool solidWalls;
        bool lostGame = false;

        Vec2Set apples;
        SnakeObj snake;

    public:
        SnakeGame(int _sizeX, int _sizeY, bool _solidWalls = true) noexcept;
        void incTimeStep();
        Vector2i getMapSize() const noexcept;
        const SnakeObj& getSnake() const noexcept;
        const Vec2Set& getApples() const noexcept;
    };
}

#endif //SNAKE_SNAKEGAME_H
