#ifndef QUNITTEST_TESTSUITE_H
#define QUNITTEST_TESTSUITE_H

struct qtestsuite_s;
typedef struct qtestsuite_s qtestsuite_t;

qtestsuite_t * create_qtestsuite(char * label);

char * qtestsuite_label(qtestsuite_t * testsuite);

#endif
