#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_management.h"
#include "room_management.h"

// Function to initialize room data
Room* initializeRoomData(int numRooms) {
    if (numRooms <= 0) {
        printf("Error: Invalid number of rooms.\n");
        return NULL;
    }

    Room *rooms = (Room*)malloc(numRooms * sizeof(Room));
    if (rooms == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize room data
    for (int i = 0; i < numRooms; i++) {
        snprintf(rooms[i].roomNumber, MAX_ROOM_NUMBER_LENGTH, "W%d", i + 101);
        rooms[i].bedCount = 0;
        rooms[i].fanCount = 0;
        rooms[i].chairCount = 0;
        rooms[i].tableCount = 0;
        rooms[i].almirahCount = 0;
        rooms[i].bulbCount = 0;
    }

    // Fetch student data and update room occupancy
    int numStudents;
    Student *students = getAllStudents(&numStudents);
    if (students == NULL) {
        printf("Error: Failed to fetch student data.\n");
        free(rooms); // Free memory allocated for rooms
        return NULL;
    }

    for (int i = 0; i < numRooms; i++) {
        for (int j = 0; j < numStudents; j++) {
            if (strcmp(students[j].room, rooms[i].roomNumber) == 0) {
                // Increment counts for items in the room
                rooms[i].bedCount++;
                rooms[i].fanCount++;
                rooms[i].chairCount++;
                rooms[i].tableCount++;
                rooms[i].almirahCount++;
                rooms[i].bulbCount++;
            }
        }
    }

    free(students); // Free memory allocated for student data

    return rooms;
}

// Function to display room details
void displayRoomDetails(Room *rooms, int numRooms) {
    if (rooms == NULL || numRooms <= 0) {
        printf("No room data to display.\n");
        return;
    }

    printf("Room Number\tBed\tFan\tChair\tTable\tAlmirah\tBulb\n");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < numRooms; i++) {
        printf("%s\t\t%d\t%d\t%d\t%d\t%d\t%d\n", rooms[i].roomNumber, rooms[i].bedCount,
               rooms[i].fanCount, rooms[i].chairCount, rooms[i].tableCount,
               rooms[i].almirahCount, rooms[i].bulbCount);
    }
}
