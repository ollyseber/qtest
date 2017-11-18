#ifndef QUNITTEST_TESTSUITE_H
#define QUNITTEST_TESTSUITE_H

#include <stdbool.h>

/*
 *  Return results for test cases, unit tests and test suites
 */
typedef enum {
    FAILED,
    PASSED
} qtestresult_t;

/*
 *  A structure representing a collection of test cases
 */
typedef struct qunittest_s qunittest_t;

/*
 *  A structure representing a collection of unit tests
 */
typedef struct qtestsuite_s qtestsuite_t;

/*
 *  Create a test suite with a description/label
 */
qtestsuite_t * create_qtestsuite(char * label);

/*
 *  Create a unit test and add it to a test suite
 */
qunittest_t * add_qunittest(char * label, qtestsuite_t * testsuite);

/*
 *  Add a test case to a unit test and set its result based on a boolean condition
 */
qtestresult_t qtest_assert_true(bool condition, char * label, qunittest_t * unittest);

/*
 *  Print test suite results
 */
void fprint_qtestsuite(FILE* stream, qtestsuite_t * testsuite);

/*
 *  Get the number of failed unit tests in a test suite
 */
int qtestsuite_unittest_failures(qtestsuite_t * testsuite);

/*
*  Get the number of failed test cases in a test suite
*/
int qtestsuite_testcase_failures(qtestsuite_t * testsuite);

/*
*  Get the number of failed test cases in a unit test
*/
int qunittest_testcase_failures(qunittest_t * unittest);

#endif
