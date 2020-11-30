#ifndef TEST_H
#define TEST_H

#include <cstdio>

#define DO_CHECK(EXPR) check(EXPR, __func__, __FILE__, __LINE__);

class Test {
protected:
    static int failedNum;

    static int totalNum;

    static void check(bool expr, const char *func, const char *filename, size_t lineNum);

public:
    static bool showFinalResult();

    virtual void runAllTests() = 0;
};

#endif
