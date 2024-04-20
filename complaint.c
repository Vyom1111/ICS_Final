#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPLAINTS 1000
#define FILENAME "complaints.csv"

struct Complaint {
    int id;
    char type[50];
    char description[100];
    char status[20];
};

struct Complaint complaints[MAX_COMPLAINTS];

// Function to load complaints from CSV file
void loadComplaints() {
    FILE *file = fopen(FILENAME, "r");
    if (file != NULL) {
        int i = 0;
        while (fscanf(file, "%d,%[^,],%[^,],%[^\n]\n", &complaints[i].id, complaints[i].type, complaints[i].description, complaints[i].status) != EOF) {
            i++;
        }
        fclose(file);
    }
}

// Function to save complaints to CSV file
void saveComplaints() {
    FILE *file = fopen(FILENAME, "w");
    if (file != NULL) {
        for (int i = 0; i < MAX_COMPLAINTS; i++) {
            if (complaints[i].id != 0) {
                fprintf(file, "%d,%s,%s,%s\n", complaints[i].id, complaints[i].type, complaints[i].description, complaints[i].status);
            }
        }
        fclose(file);
    }
}

// Function to lodge a complaint
void lodgeComplaint(int id, char type[], char description[]) {
    complaints[id].id = id;
    strcpy(complaints[id].type, type);
    strcpy(complaints[id].description, description);
    strcpy(complaints[id].status, "Pending");
}

int main() {
    loadComplaints();

    // Your complaint management system code here...

    // Example: Lodge a complaint
    lodgeComplaint(1, "Facilities", "The lights in my room are not working. %s", __TIMESTAMP__);

    // Display all complaints
    printf("All Complaints:\n");
    for (int i = 0; i < 100; i++) {
        if (complaints[i].id != 0) {
            printf("ID: %d, Type: %s, Description: %s, Status: %s\n",
                complaints[i].id, complaints[i].type, complaints[i].description, complaints[i].status);
        }
    }

    saveComplaints();
    return 0;
}
