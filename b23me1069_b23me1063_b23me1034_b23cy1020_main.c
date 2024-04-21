#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_management.h"
#include "authentication.h"
#include "complaint.h"
#include "admincomplaint.h"
#include "visitor.h"
#include "staff_management.h"
#include "man_management.h"
#include "inventory_management.h" // Include inventory management header file

int main() {

    struct Item inventory[MAX_ITEMS];
    int inventorySize = 0;
    loadInventory(inventory, &inventorySize);

    int choice;
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
        // Load room data
        
        do {
            printf("\nHostel Management System\n");
            printf("1. Add Student\n");
            printf("2. Display Students\n");
            printf("3. Register admin\n");
            printf("4. Register student\n");
            printf("5. Load complaints\n");
            printf("6. Update complaints\n");
            printf("7. Load visitors\n");
            printf("8. Add visitor\n");
            printf("9. Add Staff\n");
            printf("10. Display Staff\n");
            printf("11. Display Entry or Exit Log\n");
            printf("12. addItem\n");
            printf("13. updateInventory\n");
            printf("14. viewInventory\n");
            printf("15. Exit\n"); // Changed exit option number
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
                    loadComplaints();
                    break;
                case 6:
                    inputComplaintUpdate();
                    break;
                case 7:
                    loadVisitors();
                    break;
                case 8:
                    addVisitor();
                    break;
                case 9:
                    add_staff_case();
                    break;
                case 10:
                    display_staff();
                    break;
                case 11:
                    display_log();
                    break;
                case 12:
                    addItem(inventory, &inventorySize);
                    saveInventory(inventory, inventorySize); // Call to display available inventory function
                    break;
                case 13:
                    updateInventory(inventory, inventorySize);
                    saveInventory(inventory, inventorySize); // Call to add item to inventory function
                    break;
                case 14:
                    viewInventory(inventory, inventorySize);
                    break;
                case 15:
                    printf("Exiting...\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        } while (choice != 15);

        // Free allocated memory for rooms
    }
    else if(login_choice == 2){
        do {
            printf("\nHostel Management System\n");
            printf("1. Input complaints\n");
            printf("2. Display Staff\n");
            printf("3. Enter or Exit Hostel\n");
            printf("4. Issue Inventory Item\n");
            printf("5. Display Available Inventory\n");
            printf("6. Exit\n"); // Changed exit option number
            printf("Enter your choice: ");
            scanf("%d", &choice);
            getchar(); // Consume newline character left in the buffer

            switch (choice) {
                case 1:
                    inputComplaintDetails();
                    break;
                case 2:
                    display_staff();
                    break;
                case 3:
                    printf("Enter 1 to enter hostel, 2 to leave: ");
                    scanf("%d", &choice);
                    getchar(); // Consume newline character left in the buffer
                    enter_exit_hostel(choice);
                    break;
                case 4:
                    issueItem(inventory, inventorySize);
                    saveInventory(inventory, inventorySize);// Call to issue inventory item function
                    break;
                case 5:
                    viewInventory(inventory, inventorySize); // Call to display available inventory function
                    break;
                case 6:
                    printf("Exiting...\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        } while (choice != 6);
    }
    else{}
    return 0;
}
