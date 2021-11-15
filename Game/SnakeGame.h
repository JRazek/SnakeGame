//
// Created by user on 11.11.2021.
//

#ifndef SNAKE_SNAKEGAME_H
#define SNAKE_SNAKEGAME_H
#include <vector>
#include <deque>
#include <unordered_set>
#include "Utils.h"
#include "SnakeDirection.h"
#include "GameStatus.h"
#include <random>

namespace sng {
    class SnakeGame {
        using Vector2i = sng::Vector2<int>;
        Vector2i mapSize;

        SnakeDirection direction = SnakeDirection::DOWN;
        bool solidWalls;
        GameStatus gameStatus = GameStatus::WAITS;
        std::default_random_engine engine;

        int score = 0;
        Vec2Set apples;
        Vec2Set snakePoints;
        SnakeObj snake;


        /**
         * buffer is necessary in order to prevent double turn resulting in changing direction by 180 degrees
         */
        SnakeDirection bufferedDirection;
    public:
        SnakeGame(int _sizeX, int _sizeY, int seed = 1, bool _solidWalls = true) noexcept;
        void incTimeStep();
        void spawnApple() noexcept;
        void setDirection(SnakeDirection direction) noexcept;
        SnakeDirection getDirection() const noexcept;
        Vector2i getMapSize() const noexcept;
        const SnakeObj& getSnake() const noexcept;
        const Vec2Set& getApples() const noexcept;
        GameStatus getGameStatus() const noexcept;

        /**
         * N-sizeX, M-sizeY
         * it takes O(N*M) time and slows down the performance!
         * @return states of each cell on a map. 0 - empty, 1 - apple, 2 - snake. Snake is always above apple.
         */
        Bitmap buildStateBitmap() const noexcept;
    };
}

#endif //SNAKE_SNAKEGAME_H
