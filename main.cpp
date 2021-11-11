#include <SnakeGame.h>
#include <SnakeGameVisualiser.h>

using namespace sng;
using namespace std;
int main() {
    SnakeGame snakeGame(100, 100);
    SnakeGameVisualiser snakeGameVisualiser(snakeGame);
    snakeGameVisualiser.draw();
    return 0;
}