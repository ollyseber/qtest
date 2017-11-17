#include <stdio.h>
#include <stdlib.h>

#include "qtest/testsuite.h"
#include "testsuite_p.h"
#include "unittest_p.h"

qtestsuite_t * create_qtestsuite(char * label) {
    qtestsuite_t * testsuite = malloc(sizeof(qtestsuite_t));

    if (testsuite == NULL) {
        fprintf(stderr, "ERROR: Failed to allocate memory for qtestsuite_t!\n");
        exit(-1);
    }

    testsuite->label = label;
    testsuite->first = NULL;
    return testsuite;
}

char * qtestsuite_label(qtestsuite_t * testsuite) {
    return testsuite->label;
}

void add_qunittest(qunittest_t * unittest, qtestsuite_t * testsuite) {
    if (testsuite->length == 0) {
        testsuite->first = unittest;
        testsuite->length = 1;
        return;
    }

    qunittest_t * last_unittest = testsuite->first;

    for (int i = 1; i < testsuite->length; i++)
        last_unittest = last_unittest->next;

    last_unittest->next = unittest;
    testsuite->length++;
}

void fprint_qtestsuite(FILE* stream, qtestsuite_t * testsuite) {
    fprintf(stream, "Test Suite: %s\n\n", qtestsuite_label(testsuite));

    if (testsuite->length == 0) {
        fprintf(stream, "Error: No unit tests in test suite!\n");
        return;
    }

    qunittest_t * unittest = testsuite->first;

    for (int i = 0; i < testsuite->length; i++) {
        fprint_qunittest(stream, unittest);
        fprintf(stream, "\n");
        unittest = unittest->next;
    }
}
