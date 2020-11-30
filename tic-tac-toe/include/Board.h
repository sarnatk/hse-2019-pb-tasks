#ifndef BOARD_H
#define BOARD_H

#include <utility>

const int SIZE = 10, LINE = 5;
const std::pair<int, int> directions[8] = {std::make_pair(1, 1),
                                           std::make_pair(0, 1),
                                           std::make_pair(1, 0),
                                           std::make_pair(-1, -1),
                                           std::make_pair(-1, 1),
                                           std::make_pair(1, -1),
                                           std::make_pair(0, -1),
                                           std::make_pair(-1, 0)};

enum class Player : char {
    x = 'X', o = 'O', empty = '.'
};

class Board {
public:
    Board();

    ~Board();

    Board(Board &board) = delete;

    Player player() const;

    Player getCell(int x, int y) const;

    bool checkLineFromCell(int x, int y, std::pair<int, int> d) const;

    bool hasWinner() const;

    bool hasEmptyCells() const;

    bool canMove(int x, int y) const;

    void move(int x, int y, Player player);

    void changePlayer();

private:
    Player **field;

    Player curPlayer;
};

#endif

