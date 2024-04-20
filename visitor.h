#ifndef VISITOR_H
#define VISITOR_H

#define MAX_VISITORS 1000
#include <time.h>

struct Visitor {
    int id;
    char name[50];
    char purpose[100];
    char status[20];
    time_t timestamp;
};

void loadVisitors();
void saveVisitors();
void addVisitor();

#endif /* VISITOR_H */
