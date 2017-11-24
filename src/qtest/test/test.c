#include "qtest/testsuite.h"

int main() {
    qtestsuite_t * testsuite = create_qtestsuite("Test Suite");

    qunittest_t * unittest_1 = add_qunittest("Unit 1", testsuite);
    qtest_assert_true(true, "Case 1", unittest_1);
    qtest_assert_true(true, "Case 2", unittest_1);

    qunittest_t * unittest_2 = add_qunittest("Unit 2", testsuite);
    qtest_assert_true(false, "Case 1", unittest_2);
    qtest_assert_true(false, "Case 2", unittest_2);

    qunittest_t * unittest_3 = create_qunittest("Unit 3");
    add_existing_qunittest(unittest_3, testsuite);

    qunittest_t * unittest_4 = add_qunittest("Unit 4", testsuite);
    qtest_doubles_within_range(1e-20, 0, 1e-5, "1e-20 ~= 0", unittest_4);

    print_qtestsuite(testsuite);
    return 0;
}
