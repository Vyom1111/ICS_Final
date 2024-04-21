#include "inventory_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define INVENTORY_FILE "inventory.txt"
#define LOG_FILE "inventory_logs.txt"
#define MAX_NAME_LENGTH 50

// Function to record inventory issuance in the log
void log_inventory_issue(char* student_name, char* item) {
    // Get current date and time
    time_t raw_time;
    struct tm *timeinfo;
    char timestamp[50];

    time(&raw_time);
    timeinfo = localtime(&raw_time);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

    // Log the issuance of inventory item with date and time
    FILE *log_file;
    log_file = fopen(LOG_FILE, "a"); // Open the file in append mode
    
    if (log_file == NULL) {
        printf("Error opening log file!\n");
        return;
    }
    
    fprintf(log_file, "%s issued %s at %s\n", student_name, item, timestamp);
    fclose(log_file);
}

// Function to issue an item from the inventory
void issue_inventory_item(char* student_name, char* item) {
    // Open the inventory file
    FILE *inventory_file;
    inventory_file = fopen(INVENTORY_FILE, "r+"); // Open the file in read/write mode
    
    if (inventory_file == NULL) {
        printf("Error opening inventory file!\n");
        return;
    }

    // Check if the item is available in the inventory
    char line[100];
    int found = 0;
    while (fgets(line, sizeof(line), inventory_file) != NULL) {
        char *token = strtok(line, ":");
        if (strcmp(token, item) == 0) {
            found = 1;
            token = strtok(NULL, ":");
            int quantity = atoi(token);
            if (quantity > 0) {
                // Prompt user for the quantity of the item to issue
                int numItems;
                printf("Enter the quantity of '%s' to issue: ", item);
                scanf("%d", &numItems);
                getchar(); // Consume newline character left in the buffer
                if (numItems > quantity) {
                    printf("Insufficient quantity available for '%s'\n", item);
                    break;
                }
                // Move file pointer back to overwrite the line
                fseek(inventory_file, -strlen(line), SEEK_CUR);
                // Decrement the quantity of the item by the number of items to issue
                fprintf(inventory_file, "%s: %d\n", item, quantity - numItems);
                // Log the issuance of the item
                log_inventory_issue(student_name, item);
                printf("Issued %d '%s'(s) to %s\n", numItems, item, student_name);
            } else {
                printf("Item '%s' is out of stock\n", item);
            }
            break;
        }
    }

    if (!found) {
        printf("Item '%s' not found in inventory\n", item);
    }

    fclose(inventory_file);
}


// Function to prompt user for input parameters and issue an item from the inventory
void prompt_issue_inventory_item() {
    char student_name[MAX_NAME_LENGTH];
    char item[MAX_NAME_LENGTH];

    // Prompt user for student name
    printf("Enter student name: ");
    fgets(student_name, sizeof(student_name), stdin);
    strtok(student_name, "\n"); // Remove newline character

    // Prompt user for item name
    printf("Enter item name: ");
    fgets(item, sizeof(item), stdin);
    strtok(item, "\n"); // Remove newline character

    // Issue the item
    issue_inventory_item(student_name, item);
}

// Function to display the available items in the inventory
void display_inventory() {
    FILE *inventory_file;
    inventory_file = fopen(INVENTORY_FILE, "r"); // Open the file in read mode
    
    if (inventory_file == NULL) {
        printf("Error opening inventory file!\n");
        return;
    }

    printf("Available Inventory Items:\n");
    char line[100];
    while (fgets(line, sizeof(line), inventory_file) != NULL) {
        char *token = strtok(line, ":");
        printf("%s: ", token); // Print item name
        token = strtok(NULL, ":");
        printf("%s", token); // Print quantity
    }

    fclose(inventory_file);
    
}
// Function to add an item to the inventory with a specified quantity
void add_inventory_item(char* item, int quantity) {
    // Open the inventory file in append mode to add a new item
    FILE *inventory_file;
    inventory_file = fopen(INVENTORY_FILE, "a");
    
    if (inventory_file == NULL) {
        printf("Error opening inventory file!\n");
        return;
    }

    // Write the new item with quantity to the inventory file
    fprintf(inventory_file, "%s: %d\n", item, quantity);

    printf("Item '%s' added to inventory with quantity %d\n", item, quantity);

    fclose(inventory_file);
}

// Function to handle the case for adding an item to the inventory
void add_inventory_item_case() {
    char new_item[MAX_NAME_LENGTH];
    int quantity;
    printf("Enter the name of the new item: ");
    fgets(new_item, sizeof(new_item), stdin);
    strtok(new_item, "\n"); // Remove newline character

    printf("Enter the quantity of the new item: ");
    scanf("%d", &quantity);
    getchar(); // Consume newline character left in the buffer

    add_inventory_item(new_item, quantity); // Call to add item to inventory function
}
