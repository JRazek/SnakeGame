//
// Created by user on 11.11.2021.
//

#include "SnakeGame.h"


void sng::SnakeGame::incTimeStep() {

    constexpr static auto pointOK = [](const Vector2i& p, int _sizeX, int _sizeY){
        return p.x >= 0 && p.x < _sizeX && p.y >= 0 && p.y < _sizeY;
    };

    snake.pop_back();
    Vector2i next = snake.front();
    if(direction == 0){
        next.y -= 1;
    }else if(direction == 1){
        next.x += 1;
    }else if(direction == 2){
        next.y += 1;
    }else{
        next.x -= 1;
    }
    if(solidWalls){
        if(pointOK(next, sizeX, sizeY))
            snake.push_front(next);
        else
            lostGame = true;
    }else{
        throw std::logic_error("NOT IMPLEMENTED!");
    }
}

sng::SnakeGame::SnakeGame(int _sizeX, int _sizeY, bool _solidWalls) :
sizeX(_sizeX),
sizeY(_sizeY),
solidWalls(_solidWalls)
{}
