#pragma once

/**
 * @struct bstNode
 * @brief Represents a single node in a binary search tree
 *
 * Contains an integer data item and pointers to its left and right children.
 */
typedef struct bstNode {
    int data_item;
    struct bstNode* left;
    struct bstNode* right;
} *BSTNodePtr;

/**
 * @struct bst
 * @brief Represents a binary search tree
 *
 * Contains a pointer to the root node of the BST.
 */
typedef struct bst {
    BSTNodePtr root;
} BST;

// Function prototypes
BST new_bst();
BSTNodePtr find_bst(BST* self, int n);
void insert_bst(BST* self, int n);
void delete_bst(BST* self, int n);
void print_in_order_bst(BST* self);
void print_pre_order_bst(BST* self);
void print_post_order_bst(BST* self);
int height_bst(BST* self);
void destroy_bst(BST* self);
void bst_test(); // Prototype for testing the BST functionalities

