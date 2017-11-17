#include <stdio.h>
#include <stdlib.h>

#include "qunittest/testsuite.h"

struct qunittest_s {
    char * label;
    qtestcase_t * first;
    qunittest_t * next;
};

qunittest_t * create_qunittest(char * label) {
    qunittest_t * unittest = malloc(sizeof(qunittest_t));

    if (unittest == NULL) {
        fprintf(stderr, "ERROR: Failed to allocate memory for qtestsuite_t!\n");
        exit(-1);
    }

    unittest->label = label;
    unittest->first = NULL;
    return unittest;
}

char * qunittest_label(qunittest_t * unittest) {
    return unittest->label;
}
