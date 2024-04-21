#ifndef COMPLAINT_H
#define COMPLAINT_H

#define MAX_COMPLAINTS 100
#define FILENAME "complaints.txt"

// Structure to represent a complaint
struct Complaint {
    int id;
    char name[50];
    char roll[20];
    char room[10];
    char type[50];
    char description[100];
    char status[20];
    char timestamp[20];
};

// Function declarations
void loadComplaints();
void saveComplaints();
void lodgeComplaint(int id, char name[], char roll[], char room[], char type[], char description[]);
void inputComplaintDetails();
void updateComplaintStatus(int id, char newStatus[]);

#endif /* COMPLAINT_H */
