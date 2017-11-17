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
*  A structure representing a test case
*/
typedef struct qtestcase_s qtestcase_t;

qtestcase_t * create_qtestcase(char * label);

char * qtestcase_label(qtestcase_t * testcase);

qtestresult_t qtestcase_result(qtestcase_t * testcase);

qtestcase_t * q_assert_true(bool condition, char * label);

void fprint_qtestcase(FILE* stream, qtestcase_t * testcase);

/*
 *  A structure representing a collection of test cases
 */
typedef struct qunittest_s qunittest_t;

qunittest_t * create_qunittest(char * label);

char * qunittest_label(qunittest_t * unittest);

void add_qtestcase(qtestcase_t * testcase, qunittest_t * unittest);

void fprint_qunittest(FILE* stream, qunittest_t * unittest);

/*
 *  A structure representing a collection of unit tests
 */
typedef struct qtestsuite_s qtestsuite_t;

qtestsuite_t * create_qtestsuite(char * label);

char * qtestsuite_label(qtestsuite_t * testsuite);

#endif
