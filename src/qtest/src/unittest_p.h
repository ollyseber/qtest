#ifndef QUNITTEST_UNITTEST_H
#define QUNITTEST_UNITTEST_H

#include "qtest/testsuite.h"

struct qunittest_s {
    char * label;
    int length;
    qtestcase_t * first;
    qunittest_t * next;
};

#endif
