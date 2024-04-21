#ifndef INVENTORY_MANAGEMENT_H
#define INVENTORY_MANAGEMENT_H

// Function prototypes
void log_inventory_issue(char* student_name, char* item);
void issue_inventory_item(char* student_name, char* item);
void display_inventory();
void prompt_issue_inventory_item();
void add_inventory_item(char* item, int quantity);
void add_inventory_item_case();

#endif /* INVENTORY_MANAGEMENT_H */
