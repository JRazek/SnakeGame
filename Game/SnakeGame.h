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
        using Vector2i = sng::Utils::Vector2i;
        constexpr static auto hashVector = [](const Vector2i& v){
            u_int xHash = std::hash<int>()(v.x);
            u_int yHash = std::hash<int>()(v.y)/2;
            return xHash^yHash;
        };

        int sizeX, sizeY;
        /**
         * 0 - up, 1 - right, 2 - down, 3 - left
         */
        int direction = 0;
        bool solidWalls;
        bool lostGame = false;

        std::unordered_set<Vector2i, decltype(hashVector)> apples;

        std::deque<Vector2i> snake;

    public:
        SnakeGame(int _sizeX, int _sizeY, bool _solidWalls = true);
        void incTimeStep();
    };
}

#endif //SNAKE_SNAKEGAME_H
