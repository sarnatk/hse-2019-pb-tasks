#ifndef BOARDTEST_H
#define BOARDTEST_H

#include "Test.h"
#include "Board.h"
#include <cstdio>

class BoardTest : public Test {
private:
    static void testGetCellO();

    static void testGetCellX();

    static void testGetCellEmpty();

    static void testCanMoveO();

    static void testCanMoveFilled();

    static void testCanMoveBorders();

    static void testMoveO();

    static void testMoveX();

    static void testMoveNot();

    static void testChangePlayerStart();

    static void testChangePlayerEven();

    static void testChangePlayerOdd();

    static void testCheckLineFromCellVerticalO();

    static void testCheckLineFromCellVerticalX();

    static void testCheckLineFromCellVerticalNot();

    static void testCheckLineFromCellHorizontalO();

    static void testCheckLineFromCellHorizontalX();

    static void testCheckLineFromCellHorizontalNot();

    static void testCheckLineFromCellDiagonalO();

    static void testCheckLineFromCellDiagonalX();

    static void testCheckLineFromCellDiagonalNot();

    static void testHasWinnerO();

    static void testHasWinnerX();

    static void testHasWinnerNot();

    static void testHasEmptyCellsStart();

    static void testHasEmptyCellsProcess();

    static void testHasEmptyCellsDraw();

public:
    void runAllTests() override;
};

#endif

