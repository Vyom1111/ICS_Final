#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "complaint.h"
#include "AdminComplaint.h"

#define MAX_COMPLAINTS 100

// Structure to represent a complaint
struct Complaint complaints[MAX_COMPLAINTS];

// Function to load complaints from file and print them
void loadComplaints() {
    FILE *file = fopen(FILENAME, "r");
    if (file != NULL) {
        printf("Existing Complaints:\n");
        printf("ID\tName\tRoll\tRoom\tType\tDescription\tStatus\tTimestamp\n");
        printf("-------------------------------------------------------------------------------------\n");
        
        int i = 0;
        while (fscanf(file, "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", 
                      &complaints[i].id, complaints[i].name, complaints[i].roll, complaints[i].room,
                      complaints[i].type, complaints[i].description, complaints[i].status, complaints[i].timestamp) != EOF) {
            printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", 
                   complaints[i].id, complaints[i].name, complaints[i].roll, complaints[i].room,
                   complaints[i].type, complaints[i].description, complaints[i].status, complaints[i].timestamp);
            i++;
        }
        fclose(file);
    }
}
void inputComplaintDetails() {
    int id;
    char name[50];
    char roll[20];
    char room[10];
    char type[50];
    char description[100];

    // Prompt user for complaint details
    printf("Enter complaint ID: ");
    scanf("%d", &id);
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter roll number: ");
    scanf("%s", roll);
    printf("Enter room number: ");
    scanf("%s", room);
    printf("Enter complaint type: ");
    scanf("%s", type);
    printf("Enter complaint description: ");
    scanf("%s", description);

    // Lodge the complaint with provided inputs
    lodgeComplaint(id, name, roll, room, type, description);
    saveComplaints();
}
// Function to save complaints to file
void saveComplaints() {
    FILE *file = fopen(FILENAME, "w");
    if (file != NULL) {
        for (int i = 0; i < MAX_COMPLAINTS; i++) {
            if (complaints[i].id != 0) {
                fprintf(file, "%d,%s,%s,%s,%s,%s,%s,%s\n", 
                        complaints[i].id, complaints[i].name, complaints[i].roll, complaints[i].room,
                        complaints[i].type, complaints[i].description, complaints[i].status, complaints[i].timestamp);
            }
        }
        fclose(file);
    }
}

// Function to lodge a complaint
void lodgeComplaint(int id, char name[], char roll[], char room[], char type[], char description[]) {
    complaints[id].id = id;
    strcpy(complaints[id].name, name);
    strcpy(complaints[id].roll, roll);
    strcpy(complaints[id].room, room);
    strcpy(complaints[id].type, type);
    strcpy(complaints[id].description, description);
    strcpy(complaints[id].status, "Pending");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(complaints[id].timestamp, "%d-%02d-%02d %02d:%02d:%02d", 
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
            
}

void inputComplaintUpdate() {
    int id;
    char newStatus[20];
    char comment[100];

    // Prompt user for complaint update details
    printf("Enter complaint ID to update status: ");
    scanf("%d", &id);
    printf("Enter new status: ");
    scanf("%s", newStatus);
    printf("Enter admin comment: ");
    scanf("%s", comment);

    // Update the complaint status with provided inputs
    updateComplaintStatus(id, newStatus, comment);
}

// Function to update complaint status by admin
void updateComplaintStatus(int id, char newStatus[], char comment[]) {
    for (int i = 0; i < MAX_COMPLAINTS; i++) {
        if (complaints[i].id == id) {
            strcpy(complaints[i].status, newStatus);
            strcat(complaints[i].status, " - ");
            strcat(complaints[i].status, comment);
            break;
        }
    }
}

