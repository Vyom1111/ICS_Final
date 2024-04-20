#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_management.h"
#include "room_management.h"
#include "authentication.h"

int main() {
    int choice;

    // registerAdminUser();
    //loginUser();
    int login_choice;

    

    do {
        printf("Enter choice for login:\n");
        printf("1. Admin\n2. Student\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &login_choice);
        getchar(); // Consume newline character left in the buffer

        switch (login_choice) {
            case 1:
                if(adminUser()){
                    break;
                }
                break;
            case 2:
                if(loginUser()){
                    break;
                }
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (!(login_choice > 0 && login_choice < 4));
    
    


    do {
        printf("\nHostel Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left in the buffer

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
