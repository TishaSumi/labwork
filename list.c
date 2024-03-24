#include <stdio.h>
#include "list.h"

// Function Prototypes for Menu Operations
void option_insert(List* my_list);
void option_delete(List* my_list);
void option_print(List* my_list);

int main() {
    // Step 3: Menu-Driven Interface
    List my_list = new_list(); // Create a List called my_list
    int quit = 0; // Indicates when to exit the menu

    while (!quit) {
        int option;
        // Print the menu and get user choice
        printf("\nMenu:\n");
        printf("1. Insert an integer at the front\n");
        printf("2. Delete an integer\n");
        printf("3. Print the list\n");
        printf("0. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option) {
        case 0: // Exit the menu
            quit = 1;
            break;
        case 1: // Insert an integer
            option_insert(&my_list);
            break;
        case 2: // Delete an integer
            option_delete(&my_list);
            break;
        case 3: // Print the list
            option_print(&my_list);
            break;
        default: // Invalid option
            printf("Invalid option. Please try again.\n");
        }
    }

    // Clean up the list before exiting
    destroy_list(&my_list);
    return 0;
}

// Function to insert an integer at the front of the list
void option_insert(List* my_list) {
    int data;
    printf("Enter an integer to insert at the front of the list: ");
    scanf("%d", &data);
    insert_at_front(my_list, data);
}

// Function to delete an integer from the list
void option_delete(List* my_list) {
    int data;
    printf("Enter an integer to delete from the list: ");
    scanf("%d", &data);
    delete_list(my_list, data);
}

// Function to print the list
void option_print(List* my_list) {
    print_list(my_list);
}
