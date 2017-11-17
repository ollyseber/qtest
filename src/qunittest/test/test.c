#include <stdio.h>

#include "qunittest/testsuite.h"

int main() {
    qtestcase_t * testcase = create_qtestcase("Example test case");

    fprintf(stdout, "Testsuite: %s\n", qtestcase_label(testcase));

    return 0;
}
