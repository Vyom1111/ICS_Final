#ifndef COMPLAINT_H
#define COMPLAINT_H

#define MAX_COMPLAINTS 1000
#define FILENAME "complaints.csv"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Complaint {
    int id;
    char type[50];
    char description[100];
    char status[20];
    time_t timestamp;
};

extern struct Complaint complaints[MAX_COMPLAINTS];

void loadComplaints();
void saveComplaints();
void lodgeComplaint(int id, char type[], char description[]);

#endif
