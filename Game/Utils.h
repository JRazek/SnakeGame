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
    struct Utils {
        template<typename T>
        struct Vector2{
            T x, y;
            bool operator==(const Vector2& v1) const noexcept {
                return x == v1.x && y == v1.y;
            }
        };
    };


    constexpr static auto hashVector2i = [](const Utils::Vector2<int>& v){
        u_int xHash = std::hash<int>()(v.x);
        u_int yHash = std::hash<int>()(v.y)/2;
        return xHash^yHash;
    };

    using Vec2Set = std::unordered_set<Utils::Vector2<int>, decltype(hashVector2i)>;
    using SnakeObj = std::deque<Utils::Vector2<int>>;

}

#endif //SNAKE_UTILS_H
