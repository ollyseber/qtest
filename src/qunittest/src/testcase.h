#include "qunittest/testsuite.h"

struct qtestcase_s {
    char * label;
    qtestresult_t result;
    qtestcase_t * next;
};
