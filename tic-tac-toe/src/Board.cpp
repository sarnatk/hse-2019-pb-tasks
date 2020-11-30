#include "Board.h"

Player Board::player() const {
    return curPlayer;
}

bool Board::checkLineFromCell(int x, int y, std::pair<int, int> d) const {
    int count = 0;
    while ((x >= 0 && x < SIZE) && (y >= 0 && y < SIZE) && (field[x][y] == curPlayer)) {
        count++;
        x += d.first;
        y += d.second;
    }
    return (count == LINE);
}

bool Board::hasWinner() const {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (field[i][j] == curPlayer) {
                for (auto direction : directions) {
                    if (checkLineFromCell(i, j, direction)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

Board::Board() {
    curPlayer = Player::o;
    field = new Player *[SIZE];
    for (int i = 0; i < SIZE; i++) {
        field[i] = new Player[SIZE];
        for (int j = 0; j < SIZE; j++) {
            field[i][j] = Player::empty;
        }
    }
}

bool Board::canMove(int x, int y) const {
    if ((x < 0) || (x >= SIZE)) return false;
    if ((y < 0) || (y >= SIZE)) return false;
    return field[x][y] == Player::empty;
}

void Board::move(int x, int y, Player player) {
    if (canMove(x, y)) {
        field[x][y] = player;
    }
}

Board::~Board() {
    for (int i = 0; i < SIZE; i++)
        delete[] field[i];
    delete[] field;
}

bool Board::hasEmptyCells() const {
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            if (field[x][y] == Player::empty) return true;
        }
    }
    return false;
}

void Board::changePlayer() {
    if (curPlayer == Player::o) {
        curPlayer = Player::x;
    } else {
        curPlayer = Player::o;
    }
}

Player Board::getCell(int x, int y) const {
    return field[x][y];
}

