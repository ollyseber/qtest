#include <stdio.h>
#include <stdlib.h>

#include "qunittest/testsuite.h"

typedef struct qunittest_s {
    char * label;
    struct qunittest_s * next;
} qunittest_t;

struct qtestsuite_s {
    char * label;
    qunittest_t * first;
};

qtestsuite_t * create_qtestsuite(char * label) {
    qtestsuite_t * suite = malloc(sizeof(qtestsuite_t));

    if (suite == NULL) {
        fprintf(stderr, "ERROR: Failed to allocate memory for qtestsuite_t!\n");
        exit(-1);
    }

    suite->label = label;
    suite->first = NULL;
    return suite;
}

char * qtestsuite_label(qtestsuite_t * testsuite) {
    return testsuite->label;
}