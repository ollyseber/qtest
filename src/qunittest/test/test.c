#include <stdio.h>

#include "qunittest/testsuite.h"

int main() {
    qtestsuite_t * suite = create_qtestsuite("Example Testsuite");

    fprintf(stdout, "Testsuite: %s\n", qtestsuite_label(suite));

    return 0;
}
