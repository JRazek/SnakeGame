#include "Game/SnakeGame.h"
#include "Game/SnakeGameVisualiser.h"

using namespace sng;
using namespace std;
int main() {
    SnakeGame snakeGame(30, 30, 3);
    snakeGame.spawnApple();
    snakeGame.spawnApple();
    SnakeGameVisualiser snakeGameVisualiser(snakeGame);
    snakeGameVisualiser.run(10);
    return 0;
}