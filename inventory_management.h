#ifndef INVENTORY_MANAGEMENT_H
#define INVENTORY_MANAGEMENT_H

#define MAX_ITEMS 100
#define INVENTORY_FILENAME "hostel_inventory.txt"

struct Item {
    char name[50];
    int stock;
};

void addItem(struct Item inventory[], int *inventorySize);
void updateInventory(struct Item inventory[], int inventorySize);
void viewInventory(struct Item inventory[], int inventorySize);
void issueItem(struct Item inventory[], int inventorySize);
void saveInventory(struct Item inventory[], int inventorySize);
void loadInventory(struct Item inventory[], int *inventorySize);

#endif /* INVENTORY_MANAGEMENT_H */
