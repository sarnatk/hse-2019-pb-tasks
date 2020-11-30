#ifndef STDIOBOARDVIEW_H
#define STDIOBOARDVIEW_H

#include "Board.h"

const int BUF_SIZE = 500;

class StdioBoardView {
public:
    StdioBoardView(Board &board, bool silentMode) : board(board), silentMode(silentMode) {};

    ~StdioBoardView() = default;

    StdioBoardView(StdioBoardView &game) = delete;

    void runGame();

    void printBoard() const;

private:
    Board &board;

    bool silentMode = false;
};

#endif

