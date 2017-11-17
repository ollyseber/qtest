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

qtestresult_t qtest_assert_true(bool condition, char * label, qunittest_t * unittest);

int qunittest_failures(qunittest_t * unittest);

void fprint_qunittest(FILE* stream, qunittest_t * unittest);

/*
 *  A structure representing a collection of unit tests
 */
typedef struct qtestsuite_s qtestsuite_t;

qtestsuite_t * create_qtestsuite(char * label);

qunittest_t * add_qunittest(char * label, qtestsuite_t * testsuite);

int qtestsuite_failures(qtestsuite_t * testsuite);

void fprint_qtestsuite(FILE* stream, qtestsuite_t * testsuite);

#endif
