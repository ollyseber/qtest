#include <stdio.h>
#include <stdlib.h>

#include "qunittest/testsuite.h"
#include "unittest.h"
#include "testcase.h"

qunittest_t * create_qunittest(char * label) {
    qunittest_t * unittest = malloc(sizeof(qunittest_t));

    if (unittest == NULL) {
        fprintf(stderr, "ERROR: Failed to allocate memory for qtestsuite_t!\n");
        exit(-1);
    }

    unittest->label = label;
    unittest->length = 0;
    unittest->first = NULL;
    return unittest;
}

char * qunittest_label(qunittest_t * unittest) {
    return unittest->label;
}

void add_qtestcase(qtestcase_t * testcase, qunittest_t * unittest) {
    if (unittest->length == 0) {
        unittest->first = testcase;
        unittest->length = 1;
        return;
    }

    qtestcase_t * last_testcase = unittest->first;

    for (int i = 1; i < unittest->length; i++)
        last_testcase = last_testcase->next;
    
    last_testcase->next = testcase;
    unittest->length++;
}

void fprint_qunittest(FILE* stream, qunittest_t * unittest) {
    fprintf(stream, "UNIT: %s\n", qunittest_label(unittest));
    
    if (unittest->length == 0) {
        fprintf(stream, "  [  SKIP  ]  No test cases in unit test!\n");
        return;
    }

    qtestcase_t * testcase = unittest->first;

    for (int i = 0; i < unittest->length; i++) {
        fprint_qtestcase(stream, testcase);
        testcase = testcase->next;
    }

    fprintf(stream, "\n");
}

int qunittest_failures(qunittest_t * unittest) {
    int count = 0;

    qtestcase_t * testcase = unittest->first;

    for (int i = 0; i < unittest->length; i++) {
        count++;
        testcase = testcase->next;
    }

    return count;
}
