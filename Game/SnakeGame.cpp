//
// Created by user on 11.11.2021.
//

#include <iostream>
#include "SnakeGame.h"


void sng::SnakeGame::incTimeStep() {
    constexpr static auto pointOK = [](const Vector2<int>& p, int _sizeX, int _sizeY, const Vec2Set& _snakePoints){
        return p.x >= 0 && p.x < _sizeX && p.y >= 0 && p.y < _sizeY && !_snakePoints.contains(p);
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
    if(!solidWalls){
        next.x = (next.x + mapSize.x) % mapSize.x;
        next.y = (next.y + mapSize.y) % mapSize.y;
    }
    if(pointOK(next, mapSize.x, mapSize.y, snakePoints)) {
        snake.push_front(next);
        snakePoints.insert(next);
    }
    else
        gameStatus = GameStatus::LOST;

    if(apples.find(next) != apples.end()) {
        apples.erase(next);
        spawnApple();
        score++;
    }
    else if(gameStatus != GameStatus::LOST){
        snakePoints.erase(snake.back());
        snake.pop_back();
    }
}

sng::SnakeGame::SnakeGame(int _sizeX, int _sizeY, int seed, bool _solidWalls) noexcept:
mapSize{_sizeX, _sizeY},
solidWalls(_solidWalls),
engine(seed){
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

void sng::SnakeGame::setDirection(SnakeDirection _direction) noexcept {
    direction = _direction;
}

void sng::SnakeGame::spawnApple() noexcept {
    std::uniform_int_distribution<> distributionX(0, mapSize.x-1);
    std::uniform_int_distribution<> distributionY(0, mapSize.y-1);
    apples.insert({distributionX(engine), distributionY(engine)});
}

GameStatus sng::SnakeGame::getGameStatus() const noexcept {
    return gameStatus;
}

SnakeDirection sng::SnakeGame::getDirection() const noexcept {
    return direction;
}

sng::Bitmap sng::SnakeGame::buildStateBitmap() const noexcept {
    Bitmap bitmap(mapSize.x, std::vector<byte>(mapSize.y, 0));
    for(auto &a : apples){
        bitmap[a.x][a.y] = 1;
    }
    for(auto &s : snakePoints){
        bitmap[s.x][s.y] = 2;
    }
    return bitmap;
}
