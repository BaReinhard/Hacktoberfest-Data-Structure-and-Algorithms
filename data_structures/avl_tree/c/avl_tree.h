#ifndef TREE_H
#define TREE_H

//tree node structure
typedef struct tlnode {
    struct tlnode *left;
    struct tlnode *right;
    int key;

    int height;
    int balancing_factor;
} TREENODE;

//function prototype
int max_height(TREENODE *left_node, TREENODE *right_node);

TREENODE *create_node(int key);

void pre_order(TREENODE *root);

TREENODE *right_rotate(TREENODE *treenode);

TREENODE *left_rotate(TREENODE *treenode);

int get_balancing_factor(TREENODE *current);

TREENODE *get_minimum_value_node(TREENODE *treenode);

TREENODE *delete(TREENODE *root, int key);

TREENODE *insert(TREENODE *current, TREENODE *treenode);

#endif