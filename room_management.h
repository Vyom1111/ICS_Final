#ifndef ROOM_MANAGEMENT_H
#define ROOM_MANAGEMENT_H

#define MAX_ROOM_NUMBER_LENGTH 10

typedef struct {
    char roomNumber[MAX_ROOM_NUMBER_LENGTH];
    int bedCount;
    int fanCount;
    int chairCount;
    int tableCount;
    int almirahCount;
    int bulbCount;
} Room;

Room* initializeRoomData(int numRooms);
void displayRoomDetails(Room *rooms, int numRooms);

#endif /* ROOM_MANAGEMENT_H */
