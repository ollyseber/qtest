#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strdup()
#include <math.h> // For fabs()

#ifdef _MSC_VER
#define strdup _strdup
#endif

#include "qtest/testsuite.h"
#include "testcase_p.h"

/* Checks whether doubles <a> and <b> are within <tolerance> percent of each other */
bool approximately_equal(double a, double b, double tolerance) {
    return fabs(a - b) <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * tolerance);
}

qtestcase_t * create_qtestcase(char * label) {
    qtestcase_t * testcase = malloc(sizeof(qtestcase_t));

    if (testcase == NULL) {
        fprintf(stderr, "ERROR: Failed to allocate memory for qtestsuite_t!\n");
        exit(-1);
    }

    testcase->label = strdup(label);
    testcase->result = FAILED;
    testcase->next = NULL;
    return testcase;
}

char * qtestcase_label(qtestcase_t * testcase) {
    return testcase->label;
}

qtestresult_t qtestcase_result(qtestcase_t * testcase) {
    return testcase->result;
}

qtestcase_t * qtestcase_assert_true(bool condition, char * label) {
    qtestcase_t * testcase = create_qtestcase(label);
    if (condition)
        testcase->result = PASSED;
    return testcase;
}

qtestcase_t * qtestcase_doubles_equal(double expected, double actual, double tolerance, char * label) {
    qtestcase_t * testcase = create_qtestcase(label);
    if (approximately_equal(expected, actual, tolerance))
        testcase->result = PASSED;
    return testcase;
}

qtestcase_t * qtestcase_doubles_within_range(double actual, double expected, double range, char * label) {
    return qtestcase_assert_true(fabs(actual - expected) <= range, label);
}

void fprint_qtestcase(FILE* stream, qtestcase_t * testcase) {
    if (qtestcase_result(testcase) == PASSED)
        fprintf(stream, "  [ PASSED ]  %s\n", qtestcase_label(testcase));
    else
        fprintf(stream, "  [ FAILED ]  %s\n", qtestcase_label(testcase));
}
