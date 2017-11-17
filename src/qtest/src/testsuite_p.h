#ifndef QUNITTEST_TESTSUITE_P_H
#define QUNITTEST_TESTSUITE_P_H

#include "qtest/testsuite.h"

struct qtestsuite_s {
    char * label;
    int length;
    qunittest_t * first;
};

#endif
