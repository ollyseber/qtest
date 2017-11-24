#ifndef QTEST_TESTSUITE_H
#define QTEST_TESTSUITE_H

#include <stdbool.h>
#include <stdio.h>

/*
    semantic version (semver.org): 1.3.0

    qtest is a small test framework library for C. It provides a test suite
    for holding a collection of unit tests that in turn hold a collection 
    of test cases.
*/

/*
    Return results for test cases, unit tests and test suites
*/
typedef enum {
    FAILED,
    PASSED
} qtestresult_t;

/*
    A structure representing a collection of test cases
*/
typedef struct qunittest_s qunittest_t;

/*
    A structure representing a collection of unit tests
*/
typedef struct qtestsuite_s qtestsuite_t;

/*
    Create a test suite with a description/label
*/
qtestsuite_t * create_qtestsuite(char * label);

/*
    Create a unit test with a description/label
*/
qunittest_t * create_qunittest(char * label);

/*
    Create a unit test and add it to a test suite
*/
qunittest_t * add_qunittest(char * label, qtestsuite_t * testsuite);

/*
    Add a unit test to a test suite
*/
qunittest_t * add_existing_qunittest(qunittest_t * unittest, qtestsuite_t * testsuite);

/*
    Add a test case to a unit test and set its result based on a boolean condition
*/
qtestresult_t qtest_assert_true(bool condition, char * label, qunittest_t * unittest);

/*
    Add a test case to a unit test and set its result based on whether two doubles are within <tolerance> percentage of each other.
*/
qtestresult_t qtest_doubles_equal(double expected, double actual, double tolerance, char * label, qunittest_t * unittest);

/*
    Add a test case to a unit test and set its result based on whether two doubles
    are within a specified range of each other.
*/
qtestresult_t qtest_doubles_within_range(double actual, double expected, double range, char * label, qunittest_t * unittest);

/*
    Print test suite results to stdout
*/
void print_qtestsuite(qtestsuite_t * testsuite);

/*
    Print test suite results to file 
*/
void fprint_qtestsuite(FILE* stream, qtestsuite_t * testsuite);

/*
    Get the number of test cases in a test suite
*/
int qtestsuite_unittest_count(qtestsuite_t * testsuite);

/*
    Get the number of failed unit tests in a test suite
*/
int qtestsuite_unittest_failures(qtestsuite_t * testsuite);

/*
    Get the number of test cases in a test suite
*/
int qtestsuite_testcase_count(qtestsuite_t * testsuite);

/*
    Get the number of failed test cases in a test suite
*/
int qtestsuite_testcase_failures(qtestsuite_t * testsuite);

#endif
