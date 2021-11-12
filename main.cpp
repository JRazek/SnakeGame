#include "Game/SnakeGame.h"
#include "Game/SnakeGameVisualiser.h"

using namespace sng;
using namespace std;
int main() {
    SnakeGame snakeGame(100, 100);
    SnakeGameVisualiser snakeGameVisualiser(snakeGame);
    snakeGameVisualiser.run(2);
    return 0;
}