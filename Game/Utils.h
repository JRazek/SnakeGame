//
// Created by user on 11.11.2021.
//

#ifndef SNAKE_UTILS_H
#define SNAKE_UTILS_H

#include <zconf.h>
#include <unordered_set>
#include <deque>

namespace sng {
    using byte = unsigned char;

    template<typename T>
    struct Vector2{
        T x, y;
        bool operator==(const Vector2<int>& v2) const noexcept {
            return x == v2.x && y == v2.y;
        }
    };

    struct hashVector2i{
        std::size_t operator()(const Vector2<int>& v){
            size_t xHash = std::hash<int>()(v.x);
            size_t yHash = std::hash<int>()(v.y)/2;
            return xHash^yHash;
        };
    };
    using Vec2Set = std::unordered_set<Vector2<int>, hashVector2i>;
    using SnakeObj = std::deque<Vector2<int>>;

}

#endif //SNAKE_UTILS_H
