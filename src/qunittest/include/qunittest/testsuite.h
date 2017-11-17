#ifndef QUNITTEST_TESTSUITE_H
#define QUNITTEST_TESTSUITE_H

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

/*
 *  A structure representing a collection of test cases
 */
typedef struct qunittest_s qunittest_t;

qunittest_t * create_qunittest(char * label);

char * qunittest_label(qunittest_t * unittest);

/*
 *  A structure representing a collection of unit tests
 */
typedef struct qtestsuite_s qtestsuite_t;

qtestsuite_t * create_qtestsuite(char * label);

char * qtestsuite_label(qtestsuite_t * testsuite);

#endif
