#include "staff_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STAFF_FILE "staff.txt"

// Function to add a staff member to the log
void add_staff(char* staff_type, char* name, char* mobile_number, int on_holiday) {
    // Log the details of the staff member
    FILE *staff_file;
    staff_file = fopen(STAFF_FILE, "a"); // Open the file in append mode
    
    if (staff_file == NULL) {
        printf("Error opening staff file!\n");
        return;
    }
    
    // Check if the staff member is on holiday
    char holiday_status[20];
    if (on_holiday) {
        strcpy(holiday_status, "On Holiday");
    } else {
        strcpy(holiday_status, "Not on Holiday");
    }
    
    fprintf(staff_file, "Type: %s, Name: %s, Mobile Number: %s, Status: %s\n", staff_type, name, mobile_number, holiday_status);
    fclose(staff_file);
}

// Function to display all staff members in the log
void display_staff() {
    // Display the details of all staff members
    FILE *staff_file;
    staff_file = fopen(STAFF_FILE, "r"); // Open the file in read mode
    
    if (staff_file == NULL) {
        printf("Error opening staff file!\n");
        return;
    }

    printf("Staff Details:\n");
    char line[100];
    while (fgets(line, sizeof(line), staff_file) != NULL) {
        printf("%s", line);
    }

    fclose(staff_file);
}

// Function for case 11
void add_staff_case() {
    char staff_type[50];
    char name[50];
    char mobile_number[20];
    int on_holiday;

    // Input staff details
    printf("Enter staff type: ");
    fgets(staff_type, sizeof(staff_type), stdin);
    strtok(staff_type, "\n"); // Remove newline character

    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    strtok(name, "\n"); // Remove newline character

    printf("Enter mobile number: ");
    fgets(mobile_number, sizeof(mobile_number), stdin);
    strtok(mobile_number, "\n"); // Remove newline character

    printf("Is the staff member on holiday? (1 for yes, 0 for no): ");
    scanf("%d", &on_holiday);
    getchar(); // Consume newline character left in the buffer

    add_staff(staff_type, name, mobile_number, on_holiday);
}
