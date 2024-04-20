#include "AdminComplaint.h"

void updateComplaintStatus(int complaintId, char newStatus[], char comment[]) {
    if (complaintId < 0 || complaintId >= MAX_COMPLAINTS || complaints[complaintId].id == 0) {
        printf("Invalid complaint ID\n");
        return;
    }

    strcpy(complaints[complaintId].status, newStatus);
    strcat(complaints[complaintId].description, "\nAdmin Comment: ");
    strcat(complaints[complaintId].description, comment);

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(complaints[complaintId].timestamp, "%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}
