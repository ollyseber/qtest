#include <stdio.h>
#include <stdlib.h>

#include "qunittest/testsuite.h"

struct qtestsuite_s {
    char * label;
    qunittest_t * first;
};

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

char * qunittest_label(qtestsuite_t * unittest) {
    return unittest->label;
}
