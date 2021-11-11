//
// Created by user on 11.11.2021.
//

#include "Utils.h"

bool sng::Utils::Vector2i::operator==(const sng::Utils::Vector2i &v1) const noexcept{
    return x == v1.x && y == v1.y;
}
