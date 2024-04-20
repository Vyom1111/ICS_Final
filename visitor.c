//Visitor Management

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VISITORS 1000
#define FILENAME "visitors.csv"

struct Visitor {
    int id;
    char name[50];
    char purpose[100];
    char status[20];
};

struct Visitor visitors[MAX_VISITORS];
int numVisitors = 0; // Track the number of visitors

// Function to load visitors from CSV file
void loadVisitors() {
    FILE *file = fopen(FILENAME, "r");
    if (file != NULL) {
        int i = 0;
        while (fscanf(file, "%d,%[^,],%[^,],%[^\n]\n", &visitors[i].id, visitors[i].name, visitors[i].purpose, visitors[i].status) != EOF) {
            i++;
        }
        fclose(file);
    }
}

// Function to save visitors to CSV file
void saveVisitors() {
    FILE *file = fopen(FILENAME, "w");
    if (file != NULL) {
        for (int i = 0; i < MAX_VISITORS; i++) {
            if (visitors[i].id != 0) {
                fprintf(file, "%d,%s,%s,%s\n", visitors[i].id, visitors[i].name, visitors[i].purpose, visitors[i].status);
            }
        }
        fclose(file);
    }
}

// Function to add a new visitor
void addVisitor(int id, char name[], char purpose[]) {
    visitors[numVisitors].id = id;
    strcpy(visitors[numVisitors].name, name);
    strcpy(visitors[numVisitors].purpose, purpose);
    strcpy(visitors[numVisitors].status, "Pending Approval");
    numVisitors++;
}

int main() {
    loadVisitors();

    int n;

do {
    printf("Visitor Management\n");
    printf("Enter:\n");
    printf("1 for Getting Visitor Log\n2 for Adding new Visitor in the log\n3 to exit from this Portal");
    scanf("%d", &n);
} while (n != 3);
    // Your visitor management system code here...

    saveVisitors();
    return 0;
}
