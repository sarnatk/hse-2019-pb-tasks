#include "Board.h"
#include "StdioBoardView.h"
#include <cstring>

int main(int argc, char **argv) {
    bool silentMode = false;
    if (argc > 1) {
        if (strcmp(argv[1], "silent") == 0) {
            silentMode = true;
        }
    }
    Board board;
    StdioBoardView game(board, silentMode);
    game.runGame();
    return 0;
}
