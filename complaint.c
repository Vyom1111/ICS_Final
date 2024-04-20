#include <stdio.h>
#include "Complaint.h"
#include "AdminComplaint.h"


struct Complaint complaints[MAX_COMPLAINTS];

void loadComplaints() {
    FILE *file = fopen(FILENAME, "r");
    if (file != NULL) {
        int i = 0;
        while (fscanf(file, "%d,%[^,],%[^,],%[^,],%[^\n]\n", &complaints[i].id, complaints[i].type, complaints[i].description, complaints[i].status, complaints[i].timestamp) != EOF) {
            i++;
        }
        fclose(file);
    }
}

void saveComplaints() {
    FILE *file = fopen(FILENAME, "w");
    if (file != NULL) {
        for (int i = 0; i < MAX_COMPLAINTS; i++) {
            if (complaints[i].id != 0) {
                fprintf(file, "%d,%s,%s,%s,%s\n", complaints[i].id, complaints[i].type, complaints[i].description, complaints[i].status, complaints[i].timestamp);
            }
        }
        fclose(file);
    }
}

void lodgeComplaint(int id, char type[], char description[]) {
    complaints[id].id = id;
    strcpy(complaints[id].type, type);
    strcpy(complaints[id].description, description);
    strcpy(complaints[id].status, "Approved");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(complaints[id].timestamp, "%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

int main() {
    loadComplaints();

    // Lodging a complaint
    int complaintId;
    char type[50];
    char description[100];

    // printf("Enter complaint ID: ");
    // scanf("%d", &complaintId);
    printf("Enter complaint type: ");
    scanf("%s", type);
    printf("Enter complaint description: ");
    scanf("%s", description);
    lodgeComplaint(complaintId, type, description);

    // Display all complaints after lodging
    printf("\nAll Complaints after lodging:\n");
    for (int i = 0; i < MAX_COMPLAINTS; i++) {
        if (complaints[i].id != 0) {
            printf("ID: %d, Type: %s, Description: %s, Status: %s, Timestamp: %s\n",
                complaints[i].id, complaints[i].type, complaints[i].description, complaints[i].status, complaints[i].timestamp);
        }
    }

    // Updating complaint status by admin
    int updateId;
    char newStatus[20];
    char comment[100];

    printf("\nEnter complaint ID to update status: ");
    scanf("%d", &updateId);
    printf("Enter new status: ");
    scanf("%s", newStatus);
    printf("Enter admin comment: ");
    scanf("%s", comment);
    updateComplaintStatus(updateId, newStatus, comment);

    // Display all complaints after update
    printf("\nAll Complaints after update:\n");
    for (int i = 0; i < MAX_COMPLAINTS; i++) {
        if (complaints[i].id != 0) {
            printf("ID: %d, Type: %s, Description: %s, Status: %s, Timestamp: %s\n",
                complaints[i].id, complaints[i].type, complaints[i].description, complaints[i].status, complaints[i].timestamp);
        }
    }

    saveComplaints();
    return 0;
}
