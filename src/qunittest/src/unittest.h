#include "qunittest/testsuite.h"

struct qunittest_s {
    char * label;
    int length;
    qtestcase_t * first;
    qunittest_t * next;
};
