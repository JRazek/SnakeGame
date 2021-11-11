//
// Created by user on 11.11.2021.
//

#ifndef SNAKE_UTILS_H
#define SNAKE_UTILS_H

namespace sng {
    using byte = unsigned char;
    struct Utils {
        struct Vector2i{
            int x, y;
            bool operator==(const Vector2i& v1) const noexcept;
        };
    };


}

#endif //SNAKE_UTILS_H
