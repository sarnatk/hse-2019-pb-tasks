#include "BoardTest.h"

void BoardTest::testGetCellO() {
    Board b;
    b.move(5, 6, Player::o);
    DO_CHECK(b.getCell(5, 6) == Player::o)
}

void BoardTest::testGetCellX() {
    Board b;
    b.move(5, 6, Player::x);
    DO_CHECK(b.getCell(5, 6) == Player::x)
}

void BoardTest::testGetCellEmpty() {
    Board b;
    b.move(5, 6, Player::o);
    b.move(1, 0, Player::x);
    DO_CHECK(b.getCell(6, 4) == Player::empty)
}

void BoardTest::testCanMoveO() {
    Board b;
    b.move(5, 6, Player::o);
    b.move(1, 0, Player::x);
    DO_CHECK(b.canMove(6, 2))
}

void BoardTest::testCanMoveFilled() {
    Board b;
    b.move(5, 6, Player::o);
    b.move(1, 0, Player::x);
    DO_CHECK(!b.canMove(1, 0))
}

void BoardTest::testCanMoveBorders() {
    Board b;
    b.move(5, 6, Player::o);
    b.move(1, 0, Player::x);
    DO_CHECK(!b.canMove(16, 2))
}

void BoardTest::testMoveO() {
    Board b;
    b.move(3, 0, Player::o);
    DO_CHECK(b.getCell(3, 0) == Player::o)
}

void BoardTest::testMoveX() {
    Board b;
    b.move(3, 0, Player::o);
    b.move(7, 7, Player::x);
    DO_CHECK(b.getCell(7, 7) == Player::x)
}

void BoardTest::testMoveNot() {
    Board b;
    b.move(3, 0, Player::o);
    b.move(7, 7, Player::x);
    b.move(7, 7, Player::o);
    DO_CHECK(b.getCell(7, 7) == Player::x)
}

void BoardTest::testChangePlayerStart() {
    Board b;
    b.changePlayer();
    DO_CHECK(b.player() == Player::x)
}

void BoardTest::testChangePlayerEven() {
    Board b;
    b.changePlayer();
    b.changePlayer();
    b.changePlayer();
    b.changePlayer();
    b.changePlayer();
    b.changePlayer();
    DO_CHECK(b.player() == Player::o)
}

void BoardTest::testChangePlayerOdd() {
    Board b;
    b.changePlayer();
    b.changePlayer();
    b.changePlayer();
    b.changePlayer();
    b.changePlayer();
    DO_CHECK(b.player() == Player::x)
}

void BoardTest::testHasEmptyCellsStart() {
    Board b;
    DO_CHECK(!b.hasEmptyCells())
}

void BoardTest::testHasEmptyCellsProcess() {
    Board b;
    b.move(0, 0, Player::o);
    b.move(7, 8, Player::x);
    b.move(7, 0, Player::o);
    b.move(6, 6, Player::x);
    b.move(2, 0, Player::o);
    b.move(5, 6, Player::x);
    b.move(3, 5, Player::o);
    b.move(7, 5, Player::x);
    b.move(3, 0, Player::o);
    b.move(7, 4, Player::x);
    DO_CHECK(!b.hasEmptyCells())
}

void BoardTest::testHasEmptyCellsDraw() {
    Board b;
    b.move(0, 0, Player::o);
    b.move(0, 1, Player::o);
    b.move(0, 2, Player::o);
    b.move(0, 3, Player::o);
    b.move(0, 4, Player::o);
    b.move(0, 5, Player::o);
    b.move(0, 6, Player::o);
    b.move(0, 7, Player::o);
    b.move(0, 8, Player::o);
    b.move(0, 9, Player::o);
    b.move(1, 0, Player::o);
    b.move(1, 1, Player::o);
    b.move(1, 2, Player::o);
    b.move(1, 3, Player::o);
    b.move(1, 4, Player::o);
    b.move(1, 5, Player::o);
    b.move(1, 6, Player::o);
    b.move(1, 7, Player::o);
    b.move(1, 8, Player::o);
    b.move(1, 9, Player::o);
    b.move(2, 0, Player::o);
    b.move(2, 1, Player::o);
    b.move(2, 2, Player::o);
    b.move(2, 3, Player::o);
    b.move(2, 4, Player::o);
    b.move(2, 5, Player::o);
    b.move(2, 6, Player::o);
    b.move(2, 7, Player::o);
    b.move(2, 8, Player::o);
    b.move(2, 9, Player::o);
    b.move(3, 0, Player::o);
    b.move(3, 1, Player::o);
    b.move(3, 2, Player::o);
    b.move(3, 3, Player::o);
    b.move(3, 4, Player::o);
    b.move(3, 5, Player::o);
    b.move(3, 6, Player::o);
    b.move(3, 7, Player::o);
    b.move(3, 8, Player::o);
    b.move(3, 9, Player::o);
    b.move(4, 0, Player::o);
    b.move(4, 1, Player::o);
    b.move(4, 2, Player::o);
    b.move(4, 3, Player::o);
    b.move(4, 4, Player::o);
    b.move(4, 5, Player::o);
    b.move(4, 6, Player::o);
    b.move(4, 7, Player::o);
    b.move(4, 8, Player::o);
    b.move(4, 9, Player::o);
    b.move(5, 0, Player::x);
    b.move(5, 1, Player::x);
    b.move(5, 2, Player::x);
    b.move(5, 3, Player::x);
    b.move(5, 4, Player::x);
    b.move(5, 5, Player::x);
    b.move(5, 6, Player::x);
    b.move(5, 7, Player::x);
    b.move(5, 8, Player::x);
    b.move(5, 9, Player::x);
    b.move(6, 0, Player::x);
    b.move(6, 1, Player::x);
    b.move(6, 2, Player::x);
    b.move(6, 3, Player::x);
    b.move(6, 4, Player::x);
    b.move(6, 5, Player::x);
    b.move(6, 6, Player::x);
    b.move(6, 7, Player::x);
    b.move(6, 8, Player::x);
    b.move(6, 9, Player::x);
    b.move(7, 0, Player::x);
    b.move(7, 1, Player::x);
    b.move(7, 2, Player::x);
    b.move(7, 3, Player::x);
    b.move(7, 4, Player::x);
    b.move(7, 5, Player::x);
    b.move(7, 6, Player::x);
    b.move(7, 7, Player::x);
    b.move(7, 8, Player::x);
    b.move(7, 9, Player::x);
    b.move(8, 0, Player::x);
    b.move(8, 1, Player::x);
    b.move(8, 2, Player::x);
    b.move(8, 3, Player::x);
    b.move(8, 4, Player::x);
    b.move(8, 5, Player::x);
    b.move(8, 6, Player::x);
    b.move(8, 7, Player::x);
    b.move(8, 8, Player::x);
    b.move(8, 9, Player::x);
    b.move(9, 0, Player::x);
    b.move(9, 1, Player::x);
    b.move(9, 2, Player::x);
    b.move(9, 3, Player::x);
    b.move(9, 4, Player::x);
    b.move(9, 5, Player::x);
    b.move(9, 6, Player::x);
    b.move(9, 7, Player::x);
    b.move(9, 8, Player::x);
    b.move(9, 9, Player::x);
    DO_CHECK(b.hasEmptyCells())
}

void BoardTest::testCheckLineFromCellVerticalO() {
    Board b;
    b.move(0, 0, Player::o);
    b.move(7, 8, Player::x);
    b.move(1, 0, Player::o);
    b.move(3, 1, Player::x);
    b.move(2, 0, Player::o);
    b.move(4, 9, Player::x);
    b.move(3, 5, Player::o);
    b.move(9, 5, Player::x);
    b.move(3, 0, Player::o);
    b.move(2, 2, Player::x);
    b.move(4, 0, Player::o);
    DO_CHECK(b.checkLineFromCell(4, 0, std::make_pair(-1, 0)))
}

void BoardTest::testCheckLineFromCellVerticalX() {
    Board b;
    b.changePlayer();
    b.move(0, 0, Player::o);
    b.move(7, 8, Player::x);
    b.move(7, 0, Player::o);
    b.move(8, 8, Player::x);
    b.move(2, 0, Player::o);
    b.move(6, 8, Player::x);
    b.move(3, 5, Player::o);
    b.move(5, 8, Player::x);
    b.move(3, 0, Player::o);
    b.move(4, 8, Player::x);
    DO_CHECK(b.checkLineFromCell(4, 8, std::make_pair(1, 0)))
}

void BoardTest::testCheckLineFromCellVerticalNot() {
    Board b;
    b.move(0, 0, Player::o);
    b.move(7, 8, Player::x);
    b.move(7, 0, Player::o);
    b.move(6, 6, Player::x);
    b.move(2, 0, Player::o);
    b.move(5, 6, Player::x);
    b.move(3, 5, Player::o);
    b.move(7, 5, Player::x);
    b.move(3, 0, Player::o);
    b.move(7, 4, Player::x);
    DO_CHECK(!b.checkLineFromCell(7, 4, std::make_pair(-1, 0)))
}

void BoardTest::testCheckLineFromCellHorizontalO() {
    Board b;
    b.move(0, 0, Player::o);
    b.move(7, 8, Player::x);
    b.move(0, 1, Player::o);
    b.move(3, 1, Player::x);
    b.move(0, 2, Player::o);
    b.move(4, 9, Player::x);
    b.move(3, 5, Player::o);
    b.move(9, 5, Player::x);
    b.move(0, 3, Player::o);
    b.move(2, 2, Player::x);
    b.move(0, 4, Player::o);
    DO_CHECK(b.checkLineFromCell(0, 4, std::make_pair(0, -1)))
}

void BoardTest::testCheckLineFromCellHorizontalX() {
    Board b;
    b.changePlayer();
    b.move(0, 0, Player::o);
    b.move(7, 8, Player::x);
    b.move(7, 0, Player::o);
    b.move(7, 7, Player::x);
    b.move(2, 0, Player::o);
    b.move(7, 6, Player::x);
    b.move(3, 5, Player::o);
    b.move(7, 5, Player::x);
    b.move(3, 0, Player::o);
    b.move(7, 4, Player::x);
    DO_CHECK(b.checkLineFromCell(7, 4, std::make_pair(0, 1)))
}

void BoardTest::testCheckLineFromCellHorizontalNot() {
    Board b;
    b.move(0, 0, Player::o);
    b.move(5, 5, Player::x);
    b.move(7, 0, Player::o);
    b.move(3, 7, Player::x);
    b.move(2, 0, Player::o);
    b.move(7, 6, Player::x);
    b.move(3, 5, Player::o);
    b.move(7, 5, Player::x);
    b.move(3, 0, Player::o);
    b.move(7, 4, Player::x);
    DO_CHECK(!b.checkLineFromCell(7, 4, std::make_pair(0, 1)))
}

void BoardTest::testCheckLineFromCellDiagonalO() {
    Board b;
    b.move(0, 0, Player::o);
    b.move(7, 8, Player::x);
    b.move(1, 1, Player::o);
    b.move(3, 1, Player::x);
    b.move(0, 2, Player::o);
    b.move(4, 9, Player::x);
    b.move(2, 2, Player::o);
    b.move(9, 5, Player::x);
    b.move(3, 3, Player::o);
    b.move(2, 2, Player::x);
    b.move(4, 4, Player::o);
    DO_CHECK(b.checkLineFromCell(4, 4, std::make_pair(-1, -1)))
}

void BoardTest::testCheckLineFromCellDiagonalX() {
    Board b;
    b.changePlayer();
    b.move(0, 0, Player::o);
    b.move(9, 1, Player::x);
    b.move(1, 1, Player::o);
    b.move(8, 2, Player::x);
    b.move(0, 2, Player::o);
    b.move(7, 3, Player::x);
    b.move(2, 2, Player::o);
    b.move(6, 4, Player::x);
    b.move(3, 3, Player::o);
    b.move(5, 5, Player::x);
    DO_CHECK(b.checkLineFromCell(5, 5, std::make_pair(1, -1)))
}

void BoardTest::testCheckLineFromCellDiagonalNot() {
    Board b;
    b.move(0, 0, Player::o);
    b.move(5, 5, Player::x);
    b.move(7, 0, Player::o);
    b.move(3, 7, Player::x);
    b.move(2, 0, Player::o);
    b.move(7, 6, Player::x);
    b.move(3, 5, Player::o);
    b.move(7, 5, Player::x);
    b.move(3, 0, Player::o);
    b.move(7, 4, Player::x);
    DO_CHECK(!b.checkLineFromCell(7, 4, std::make_pair(1, 1)))
}

void BoardTest::testHasWinnerO() {
    Board b;
    b.move(0, 0, Player::o);
    b.move(7, 8, Player::x);
    b.move(1, 1, Player::o);
    b.move(3, 1, Player::x);
    b.move(0, 2, Player::o);
    b.move(4, 9, Player::x);
    b.move(2, 2, Player::o);
    b.move(9, 5, Player::x);
    b.move(3, 3, Player::o);
    b.move(2, 2, Player::x);
    b.move(4, 4, Player::o);
    DO_CHECK(b.hasWinner())
}

void BoardTest::testHasWinnerX() {
    Board b;
    b.changePlayer();
    b.move(0, 0, Player::o);
    b.move(7, 8, Player::x);
    b.move(7, 0, Player::o);
    b.move(8, 8, Player::x);
    b.move(2, 0, Player::o);
    b.move(6, 8, Player::x);
    b.move(3, 5, Player::o);
    b.move(5, 8, Player::x);
    b.move(3, 0, Player::o);
    b.move(4, 8, Player::x);
    DO_CHECK(b.hasWinner())
}

void BoardTest::testHasWinnerNot() {
    Board b;
    b.move(0, 0, Player::o);
    b.move(1, 8, Player::x);
    b.move(7, 0, Player::o);
    b.move(8, 8, Player::x);
    b.move(2, 0, Player::o);
    b.move(6, 8, Player::x);
    b.move(3, 2, Player::o);
    b.move(5, 8, Player::x);
    b.move(3, 2, Player::o);
    b.move(4, 8, Player::x);
    DO_CHECK(!b.hasWinner())
}

void BoardTest::runAllTests() {
    testGetCellO();
    testGetCellX();
    testGetCellEmpty();

    testCanMoveO();
    testCanMoveFilled();
    testCanMoveBorders();

    testMoveO();
    testMoveX();
    testMoveNot();

    testChangePlayerStart();
    testChangePlayerEven();
    testChangePlayerOdd();

    testHasEmptyCellsStart();
    testHasEmptyCellsProcess();
    testHasEmptyCellsDraw();

    testCheckLineFromCellVerticalO();
    testCheckLineFromCellVerticalX();
    testCheckLineFromCellVerticalNot();

    testCheckLineFromCellHorizontalO();
    testCheckLineFromCellHorizontalX();
    testCheckLineFromCellHorizontalNot();

    testCheckLineFromCellDiagonalO();
    testCheckLineFromCellDiagonalX();
    testCheckLineFromCellDiagonalNot();

    testHasWinnerO();
    testHasWinnerX();
    testHasWinnerNot();
}

