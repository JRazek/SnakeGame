//
// Created by user on 11.11.2021.
//

#include "SnakeGame.h"


void sng::SnakeGame::incTimeStep() {
    constexpr static auto pointOK = [](const Vector2<int>& p, int _sizeX, int _sizeY, const Vec2Set& snakePoints){
        return p.x >= 0 && p.x < _sizeX && p.y >= 0 && p.y < _sizeY && !snakePoints.contains(p);
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
        if(pointOK(next, mapSize.x, mapSize.y, snakePoints)) {
            snake.push_front(next);
            snakePoints.insert(next);
        }
        else
            gameStatus = GameStatus::LOST;
    }else{
        throw std::logic_error("NOT IMPLEMENTED!");
    }
    if(apples.find(next) != apples.end()) {
        apples.erase(next);
        spawnApple();
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
    std::uniform_int_distribution<> distributionX(0, mapSize.x);
    std::uniform_int_distribution<> distributionY(0, mapSize.y);
    apples.insert({distributionX(engine), distributionY(engine)});
}

GameStatus sng::SnakeGame::getGameStatus() const noexcept {
    return gameStatus;
}

SnakeDirection sng::SnakeGame::getDirection() const noexcept {
    return direction;
}
