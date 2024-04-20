#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_management.h"

#define DATABASE_FILE "students.txt"
#define OUTPUT_FILE "sorted_students.txt"

// Define maximum lengths for strings
#define MAX_NAME_LENGTH 50
#define MAX_CONTACT_LENGTH 15
#define MAX_ROOM_LENGTH 10
#define MAX_ROLL_LENGTH 15

// Structure to represent a student
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char contact[MAX_CONTACT_LENGTH];
    char roll[MAX_ROLL_LENGTH];
} Student;

// Structure to represent a room
typedef struct {
    char room[MAX_ROOM_LENGTH];
    Student student;
    int isEmpty;
} Room;

// Function to fetch all student records and populate rooms
void fetchStudentsAndPopulateRooms(Room *rooms, int *numRooms) {
    // Open the database file
    FILE *file = fopen(DATABASE_FILE, "r");
    if (file == NULL) {
        printf("Error opening database file.\n");
        return;
    }

    // Initialize rooms as empty
    for (int i = 0; i < 40; i++) {
        sprintf(rooms[i].room, "E%d", i + 1);
        rooms[i].isEmpty = 1;
    }

    // Read student records from file
    while (fscanf(file, "%*[^,],%*d,%*[^,],%9[^,],%*s\n", rooms[*numRooms].room) != EOF) {
        strtok(rooms[*numRooms].room, "\n"); // Remove newline character
        rooms[*numRooms].isEmpty = 0;
        (*numRooms)++;
    }

    fclose(file);
}

// Function to compare room numbers for sorting
int compareRooms(const void *a, const void *b) {
    const Room *roomA = (const Room *)a;
    const Room *roomB = (const Room *)b;
    return strcmp(roomA->room, roomB->room);
}

// Function to write rooms and their corresponding students to file
void writeRoomsToFile(Room *rooms, int numRooms) {
    // Write rooms and their corresponding students to output file
    FILE *outputFile = fopen(OUTPUT_FILE, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return;
    }

    // Write header to output file
    fprintf(outputFile, "%-15s\t\tAge\t%-10s\t\tRoom\t\tRoll\n", "Name", "Contact");
    fprintf(outputFile, "----------------------------------------------------------------------------\n");

    // Write rooms and their corresponding students to output file
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].isEmpty) {
            fprintf(outputFile, "\t\t\t\t\t%s\t\tEmpty\n", rooms[i].room);
        } else {
            fprintf(outputFile, "%-15s\t\t%d\t%-10s\t\t%s\t\t%s\n", rooms[i].student.name, rooms[i].student.age, rooms[i].student.contact, rooms[i].room, rooms[i].student.roll);
        }
    }

    fclose(outputFile);

    printf("Rooms sorted and written to %s\n", OUTPUT_FILE);
}

int main() {
    Room rooms[40];
    int numRooms = 0;

    fetchStudentsAndPopulateRooms(rooms, &numRooms);
    qsort(rooms, numRooms, sizeof(Room), compareRooms);
    writeRoomsToFile(rooms, numRooms);

    return 0;
}
