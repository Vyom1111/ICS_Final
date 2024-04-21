#include "inventory_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Item inventory[MAX_ITEMS];
    int inventorySize = 0;

// Function to add item to inventory
void addItem(struct Item inventory[], int *inventorySize) {
    if (*inventorySize >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    printf("Enter item details:\n");
    printf("Name: ");
    scanf("%s", inventory[*inventorySize].name);
    printf("Stock: ");
    scanf("%d", &inventory[*inventorySize].stock);

    (*inventorySize)++;
    printf("Item added to inventory successfully.\n");
    
}

// Function to update inventory
void updateInventory(struct Item inventory[], int inventorySize) {
    if (inventorySize == 0) {
        printf("Inventory is empty. Please add items first.\n");
        return;
    }

    printf("Enter the name of the item to update: ");
    char itemName[50];
    scanf("%s", itemName);

    for (int i = 0; i < inventorySize; ++i) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            printf("Enter new stock for %s: ", itemName);
            scanf("%d", &inventory[i].stock);
            printf("Inventory updated successfully.\n");
            return;
        }
    }

    printf("Item not found in inventory.\n");
}

// Function to view inventory
void viewInventory(struct Item inventory[], int inventorySize) {
    printf("======= HOSTEL INVENTORY =======\n");
    printf("%-15s\tStock\n","Name");
    for (int i = 0; i < inventorySize; ++i) {
        printf("%-15s\t%d\n", inventory[i].name, inventory[i].stock);
    }
}

// Function to issue item to a student
void issueItem(struct Item inventory[], int inventorySize) {
    if (inventorySize == 0) {
        printf("Inventory is empty. Please add items first.\n");
        return;
    }

    printf("Enter the name of the item to issue: ");
    char itemName[50];
    scanf("%s", itemName);

    for (int i = 0; i < inventorySize; ++i) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            printf("Enter the quantity to issue: ");
            int quantity;
            scanf("%d", &quantity);
            if (inventory[i].stock >= quantity) {
                inventory[i].stock -= quantity;
                printf("%d %s issued successfully.\n", quantity, itemName);
            } else {
                printf("Not enough stock available for %s.\n", itemName);
            }
            return;
        }
    }

    printf("Item not found in inventory.\n");
}

// Function to save inventory to file
void saveInventory(struct Item inventory[], int inventorySize) {
    FILE *file = fopen(INVENTORY_FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < inventorySize; ++i) {
        fprintf(file, "%s %d\n", inventory[i].name, inventory[i].stock);
    }

    fclose(file);
}

// Function to load inventory from file
void loadInventory(struct Item inventory[], int *inventorySize) {
    FILE *file = fopen(INVENTORY_FILENAME, "r");
    if (file == NULL) {
        printf("Inventory file not found. Starting with empty inventory.\n");
        return;
    }

    *inventorySize = 0;
    while (!feof(file) && *inventorySize < MAX_ITEMS) {
        fscanf(file, "%s %d\n", inventory[*inventorySize].name, &inventory[*inventorySize].stock);
        (*inventorySize)++;
    }

    fclose(file);
}
