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
    int loggedIn = 0;
    do {
        printf("Enter choice for login:\n");
        printf("1. Admin\n2. Student\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &login_choice);
        getchar(); // Consume newline character left in the buffer

        switch (login_choice) {
            case 1:
                if(adminUser()){
                    loggedIn = 1;
                }
                break;
            case 2:
                if(loginUser()){
                    loggedIn = 1;
                }
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (!loggedIn);
    
    if(login_choice == 1){
        do {
            printf("\nHostel Management System\n");
            printf("1. Add Student\n");
            printf("2. Display Students\n");
            printf("3. Register admin\n");
            printf("4. Register student\n");
            printf("5. Exit\n");
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
                    registerAdminUser();
                    break;
                case 4:
                    registerUser();
                    break;
                case 5:
                    printf("Exiting...\n");
                    break;
                
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        } while (choice != 5);
    }
    else if(login_choice == 2){

    }
    else{}
    return 0;
}
