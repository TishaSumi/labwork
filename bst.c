#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

BST new_bst() {
    BST temp;
    temp.root = NULL;
    return temp;
}

BSTNodePtr find_bst_node(BSTNodePtr self, int n) {
    if (self == NULL || n == self->data_item) {
        return self;
    }
    else if (n < self->data_item) {
        return find_bst_node(self->left, n);
    }
    else {
        return find_bst_node(self->right, n);
    }
}

BSTNodePtr find_bst(BST* self, int n) {
    return find_bst_node(self->root, n);
}

BSTNodePtr insert_bst_node(BSTNodePtr self, int n) {
    if (self == NULL) {
        self = (BSTNodePtr)malloc(sizeof(struct bstNode));
        if (!self) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        self->data_item = n;
        self->left = NULL;
        self->right = NULL;
    }
    else if (n < self->data_item) {
        self->left = insert_bst_node(self->left, n);
    }
    else if (n > self->data_item) {
        self->right = insert_bst_node(self->right, n);
    }
    return self;
}

void insert_bst(BST* self, int n) {
    self->root = insert_bst_node(self->root, n);
}

BSTNodePtr min_node(BSTNodePtr self) {
    while (self && self->left != NULL) {
        self = self->left;
    }
    return self;
}

BSTNodePtr delete_bst_node(BSTNodePtr self, int n) {
    if (!self) return NULL;
    if (n < self->data_item) {
        self->left = delete_bst_node(self->left, n);
    }
    else if (n > self->data_item) {
        self->right = delete_bst_node(self->right, n);
    }
    else {
        if (!self->left) {
            BSTNodePtr temp = self->right;
            free(self);
            return temp;
        }
        else if (!self->right) {
            BSTNodePtr temp = self->left;
            free(self);
            return temp;
        }
        BSTNodePtr temp = min_node(self->right);
        self->data_item = temp->data_item;
        self->right = delete_bst_node(self->right, temp->data_item);
    }
    return self;
}

void delete_bst(BST* self, int n) {
    self->root = delete_bst_node(self->root, n);
}

void print_in_order_bst_node(BSTNodePtr self) {
    if (self) {
        print_in_order_bst_node(self->left);
        printf("%d ", self->data_item);
        print_in_order_bst_node(self->right);
    }
}

void print_in_order_bst(BST* self) {
    print_in_order_bst_node(self->root);
    printf("\n");
}

void print_pre_order_bst_node(BSTNodePtr self) {
    if (self) {
        printf("%d ", self->data_item);
        print_pre_order_bst_node(self->left);
        print_pre_order_bst_node(self->right);
    }
}

void print_pre_order_bst(BST* self) {
    print_pre_order_bst_node(self->root);
    printf("\n");
}

void print_post_order_bst_node(BSTNodePtr self) {
    if (self) {
        print_post_order_bst_node(self->left);
        print_post_order_bst_node(self->right);
        printf("%d ", self->data_item);
    }
}

void print_post_order_bst(BST* self) {
    print_post_order_bst_node(self->root);
    printf("\n");
}

int height_bst_node(BSTNodePtr self) {
    if (!self) return -1;
    int leftHeight = height_bst_node(self->left);
    int rightHeight = height_bst_node(self->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int height_bst(BST* self) {
    return height_bst_node(self->root);
}

void destroy_bst_node(BSTNodePtr self) {
    if (self != NULL) {
        destroy_bst_node(self->left); // Recursively destroy the left subtree
        destroy_bst_node(self->right); // Recursively destroy the right subtree
        free(self); // Free the current node
    }
}

void destroy_bst(BST* self) {
    destroy_bst_node(self->root); // Begin the recursive destruction from the root
    self->root = NULL; // Set the root to NULL after destruction
}

void bst_test() {
    BST tree = new_bst(); // Create a new, empty BST
    int quit = 0;
    int data;

    printf("Please enter integers to insert into the BST. Enter 0 to stop.\n");
    while (!quit) {
        printf("Enter data: ");
        scanf("%d", &data); // Read user input
        if (data != 0) {
            insert_bst(&tree, data); // Insert the data into the BST
        }
        else {
            quit = 1; // Exit the loop if the user inputs 0
        }
    }

    // Display the BST in various traversal orders
    printf("\nIn-order traversal of the BST:\n");
    print_in_order_bst(&tree);

    printf("\nPre-order traversal of the BST:\n");
    print_pre_order_bst(&tree);

    printf("\nPost-order traversal of the BST:\n");
    print_post_order_bst(&tree);

    // Display the height of the BST
    printf("\nHeight of the BST: %d\n", height_bst(&tree));

    // Cleanup: Destroy the BST to free allocated memory
    destroy_bst(&tree);
    printf("\nThe BST has been successfully destroyed.\n");
}
