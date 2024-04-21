#include "man_management.h"
#include <stdio.h>
#include <time.h>

void log_entry_exit(char* student_name, char* room_number, char* action) {
    // Get current date and time
    time_t raw_time;
    struct tm *timeinfo;
    char timestamp[50];

    time(&raw_time);
    timeinfo = localtime(&raw_time);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

    // Log the entry or exit of a student into or from their room with date and time
    FILE *log_file;
    log_file = fopen("student_logs.txt", "a"); // Open the file in append mode
    
    if (log_file == NULL) {
        printf("Error opening log file!\n");
        return;
    }
    
    fprintf(log_file, "%s %s room %s at %s\n", student_name, action, room_number, timestamp);
    fclose(log_file);
}

void enter_room(char* student_name, char* room_number) {
    // Record the entry of a student into their room
    printf("%s entered room %s\n", student_name, room_number);
    log_entry_exit(student_name, room_number, "entered");
}

void leave_room(char* student_name, char* room_number) {
    // Record the exit of a student from their room
    printf("%s left room %s\n", student_name, room_number);
    log_entry_exit(student_name, room_number, "left");
}

void display_log() {
    // Display the log of entry and exit
    FILE *log_file;
    log_file = fopen("student_logs.txt", "r"); // Open the file in read mode
    
    if (log_file == NULL) {
        printf("Error opening log file!\n");
        return;
    }

    printf("Entry/Exit Log:\n");
    char line[100];
    while (fgets(line, sizeof(line), log_file) != NULL) {
        printf("%s", line);
    }

    fclose(log_file);
}

void enter_exit_hostel(int choice) {
    char student_name[100], room_number[100];
    printf("Enter student name: ");
    scanf("%s", student_name);
    printf("Enter room number: ");
    scanf("%s", room_number);
    if (choice == 1) {
        enter_room(student_name, room_number);
    } else if (choice == 2) {
        leave_room(student_name, room_number);
    } else {
        printf("Invalid choice.\n");
    }
}
