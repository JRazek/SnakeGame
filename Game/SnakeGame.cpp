//
// Created by user on 11.11.2021.
//

#include "SnakeGame.h"


void sng::SnakeGame::incTimeStep() {
    if(lostGame)
        return;

    constexpr static auto pointOK = [](const Vector2<int>& p, int _sizeX, int _sizeY){
        return p.x >= 0 && p.x < _sizeX && p.y >= 0 && p.y < _sizeY;
    };

    Vector2<int> next = snake.front();
    if(direction == SnakeDirection::UP){
        next.y -= 1;
    }else if(direction == SnakeDirection::RIGHT){
        next.x += 1;
    }else if(direction == SnakeDirection::DOWN){
        next.y += 1;
    }else if (direction == SnakeDirection::LEFT){
        next.x -= 1;
    }
    if(solidWalls){
        if(pointOK(next, mapSize.x, mapSize.y))
            snake.push_front(next);
        else
            lostGame = true;
    }else{
        throw std::logic_error("NOT IMPLEMENTED!");
    }
    if(apples.find(next) != apples.end())
        apples.erase(next);
    else
        snake.pop_back();
}

sng::SnakeGame::SnakeGame(int _sizeX, int _sizeY, bool _solidWalls) noexcept:
mapSize{_sizeX, _sizeY},
solidWalls(_solidWalls){
    snake.push_front(mapSize/2);
}

sng::SnakeGame::Vector2i sng::SnakeGame::getMapSize() const noexcept {
    return mapSize;
}

const sng::SnakeObj& sng::SnakeGame::getSnake() const noexcept {
    return snake;
}

const sng::Vec2Set& sng::SnakeGame::getApples() const noexcept {
    return apples;
}

void sng::SnakeGame::setDirection(SnakeDirection _direction) {
    direction = _direction;
}
