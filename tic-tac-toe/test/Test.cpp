#include "Test.h"

int Test::totalNum;

int Test::failedNum;

bool Test::showFinalResult() {
    printf("%d of %d tests passed successfully.\n", totalNum - failedNum, totalNum);
    return !failedNum;
}

void Test::check(bool expr, const char *func, const char *filename, size_t lineNum) {
    totalNum++;
    if (!expr) {
        printf("Function %s, line %zu in file %s failed.\n", func, lineNum, filename);
        failedNum++;
    }
}
