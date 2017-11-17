#include <stdio.h>
#include <stdlib.h>

#include "qunittest/testsuite.h"

struct qtestcase_s {
    char * label;
    qtestresult_t result;
    qtestcase_t * next;
};

qtestcase_t * create_qtestcase(char * label) {
    qtestcase_t * testcase = malloc(sizeof(qtestcase_t));

    if (testcase == NULL) {
        fprintf(stderr, "ERROR: Failed to allocate memory for qtestsuite_t!\n");
        exit(-1);
    }

    testcase->label = label;
    testcase->result = FAILED;
    testcase->next = NULL;
    return testcase;
}

char * qtestcase_label(qtestcase_t * testcase) {
    return testcase->label;
}

