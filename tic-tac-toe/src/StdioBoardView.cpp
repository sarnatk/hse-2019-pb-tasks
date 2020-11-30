#include "StdioBoardView.h"
#include <cstdio>
#include <iostream>
#include <cstring>

void StdioBoardView::printBoard() const {
    printf("\n");
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            printf("%c", (char) board.getCell(x, y));
        }
        printf("\n");
    }
}

void StdioBoardView::runGame() {
    int x, y, count = 0, x_buf, y_buf;
    bool wasBad = false;
    char buf[BUF_SIZE] = "", junk[BUF_SIZE] = "", c_buf = '*';
    while (true) {
        if ((!silentMode && !wasBad) || (!board.hasEmptyCells())) printBoard();
        if (!board.hasEmptyCells()) break;
        printf("%c move: ", (char) board.player());
        std::cin.getline(buf, BUF_SIZE);
        count = sscanf(buf, "%d%c %d%s", &x_buf, &c_buf, &y_buf, junk);
        if (c_buf == ' ' && count == 3 && !strlen(junk)) {
            x = x_buf;
            y = y_buf;
        } else {
            printf("Bad move!\n");
            junk[0] = '\0';
            wasBad = true;
            continue;
        }
        if ((x == -1) && (y == -1)) return;
        if (board.canMove(x, y)) {
            board.move(x, y, board.player());
        } else {
            printf("Bad move!\n");
            wasBad = true;
            continue;
        }
        if (board.hasWinner()) {
            printBoard();
            printf("%c wins!\n", (char) board.player());
            return;
        }
        board.changePlayer();
        wasBad = false;
    }
    printf("Draw.\n");
}

