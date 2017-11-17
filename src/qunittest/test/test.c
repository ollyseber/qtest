#include <stdio.h>

#include "qunittest/testsuite.h"

int main() {
    qunittest_t * unittest = create_qunittest("Unit 1");

    add_qtestcase(
        q_assert_true(true, "Case 1"), 
        unittest);

    add_qtestcase(
        q_assert_true(true, "Case 2"),
        unittest);

    fprint_qunittest(stdout, unittest);
    printf("Done.\n");
    return 0;
}
