#include "Visitor.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

struct Visitor visitors[MAX_VISITORS];
int numVisitors = 0;

void loadVisitors() {
    FILE *file = fopen("visitors.csv", "r");
    if (file != NULL) {
        int i = 0;
        while (fscanf(file, "%d,%[^,],%[^,],%[^,],%ld\n", &visitors[i].id, visitors[i].name, visitors[i].purpose, visitors[i].status, &visitors[i].timestamp) != EOF) {
            i++;
        }
        fclose(file);
        numVisitors = i; // Update the number of visitors
    }
}

void saveVisitors() {
    FILE *file = fopen("visitors.csv", "w");
    if (file != NULL) {
        for (int i = 0; i < numVisitors; i++) {
            fprintf(file, "%d,%s,%s,%s,%ld\n", visitors[i].id, visitors[i].name, visitors[i].purpose, visitors[i].status, visitors[i].timestamp);
        }
        fclose(file);
    }
}

void addVisitor() {
    if (numVisitors >= MAX_VISITORS) {
        printf("Visitor limit reached!\n");
        return;
    }

    FILE *file = fopen("visitors.csv", "a+");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Count the number of lines in the file to get the next visitor ID
    int id = numVisitors + 1;

    printf("Adding New Visitor\n");
    printf("Enter Visitor Name: ");
    scanf("%s", visitors[numVisitors].name);
    printf("Enter Purpose of Visit: ");
    scanf("%s", visitors[numVisitors].purpose);
    strcpy(visitors[numVisitors].status, "Approved");
    visitors[numVisitors].timestamp = time(NULL);
    visitors[numVisitors].id = id;

    // Append the new visitor entry to the file
    fprintf(file, "%d,%s,%s,%s,%ld\n", visitors[numVisitors].id, visitors[numVisitors].name, visitors[numVisitors].purpose, visitors[numVisitors].status, visitors[numVisitors].timestamp);
    fclose(file);

    numVisitors++;
}

#include "Visitor.h"
#include <stdio.h>

int main() {
    int choice;
    loadVisitors();

    do {
        printf("\nVisitor Management\n");
        printf("1. View Visitor Log\n");
        printf("2. Add New Visitor\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Code to view visitor log
                break;
            case 2:
                addVisitor();
                break;
            case 3:
                saveVisitors();
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
