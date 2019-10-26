#include "avl_tree.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

/*
 * create_node(): creates a tree node for the given integer key and returns a reference to it
 */
TREENODE *create_node(int key) {
    TREENODE *treenode;
    if ((treenode = (TREENODE *) malloc(sizeof(TREENODE)))) {
        treenode->key = key;
        treenode->left = NULL;
        treenode->right = NULL;

        treenode->height = 0;
        treenode->balancing_factor = 0;

        return treenode;
    }

    errno = ENOMEM;
    perror("Memory couldn't be allocated to tree node!");
    return NULL;
}

/*
 * insert(): recursive function to insert a given node to the AVL tree
 */
TREENODE *insert(TREENODE *current, TREENODE *treenode) {
    if (current == NULL) {
        return treenode;
    }
    if (treenode->key < current->key) {
        current->left = insert(current->left, treenode);
    } else if (treenode->key > current->key) {
        current->right = insert(current->right, treenode);
    } else {
        return current;
    }

    current->height = max_height(current->left, current->right) + 1;
    current->balancing_factor = get_balancing_factor(current);

    if (current->balancing_factor > 1 && treenode->key < current->left->key) {
        return right_rotate(current);
    }
    if (current->balancing_factor < -1 && treenode->key > current->right->key) {
        return left_rotate(current);
    }
    if (current->balancing_factor > 1 && treenode->key > current->left->key) {
        current->left = left_rotate(current->left);
        return right_rotate(current);
    }
    if (current->balancing_factor < -1 && treenode->key < current->right->key) {
        current->right = right_rotate(current->right);
        return left_rotate(current);
    }

    return current;
}

/*
 * delete(): recursive function to delete node with a given key from the AVL tree
 */
TREENODE *delete(TREENODE *current, int key) {

    if (current == NULL) {
        return current;
    }

    if (key < current->key) {
        current->left = delete(current->left, key);
    } else if (key > current->key) {
        current->right = delete(current->right, key);
    } else {
        TREENODE *temp_node;
        if (current->left == NULL || current->right == NULL) {
            temp_node = current->left ? current->left : current->right;

            if (temp_node == NULL) {
                temp_node = current;
                current = NULL;
            } else {
                *current = *temp_node;
            }

            free(temp_node);
        } else {
            temp_node = get_minimum_value_node(current->right);
            current->key = temp_node->key;
            current->right = delete(current->right, temp_node->key);
        }
    }

    if (current == NULL) {
        return current;
    }

    current->height = max_height(current->left, current->right) + 1;
    current->balancing_factor = get_balancing_factor(current);

    if (current->balancing_factor > 1 && get_balancing_factor(current->left) >= 0) {
        return right_rotate(current);
    }
    if (current->balancing_factor > 1 && get_balancing_factor(current->left) < 0) {
        current->left = left_rotate(current->left);
        return right_rotate(current);
    }
    if (current->balancing_factor < -1 && get_balancing_factor(current->right) <= 0) {
        return left_rotate(current);
    }
    if (current->balancing_factor < -1 && get_balancing_factor(current->right) > 0) {
        current->right = right_rotate(current->right);
        return left_rotate(current);
    }

    return current;
}

/*
 * get_minimum_value_node(): computes the leaf left node of a given node
 */
TREENODE *get_minimum_value_node(TREENODE *treenode) {
    TREENODE *current = treenode;

    while (current->left != NULL)
        current = current->left;

    return current;
}

/*
 * pre_order(): recursive function to display node in the AVL tree in the pre order form
 */
void pre_order(TREENODE *root) {
    if (root != NULL) {
        fprintf(stdout, "%d ", root->key);
        pre_order(root->left);
        pre_order(root->right);
    }
}

/*
 * max_height(): computes the maximum height among two given nodes
 */
int max_height(TREENODE *left_node, TREENODE *right_node) {
    if (left_node == NULL && right_node == NULL) {
        return 0;
    }

    if (left_node == NULL) {
        return right_node->height;
    } else if (right_node == NULL) {
        return left_node->height;
    } else {
        return left_node->height > right_node->height ? left_node->height : right_node->height;
    }
}

/*
 * get_balancing_factor: computes the balancing factor for the given node
 */
int get_balancing_factor(TREENODE *current) {
    if (current == NULL || (current->left == NULL && current->right == NULL)) {
        return 0;
    }

    if (current->left == NULL) {
        return -(current->right->height);
    } else {
        if (current->right == NULL) {
            return current->left->height;
        } else {
            return current->left->height - current->right->height;
        }
    }
}

/*
 * right_rotate(): right rotation of AVL tree node
 */
TREENODE *right_rotate(TREENODE *treenode) {
    TREENODE *left_node = treenode->left;
    TREENODE *left_right_node = left_node->right;

    left_node->right = treenode;
    treenode->left = left_right_node;

    treenode->height = max_height(treenode->left, treenode->right) + 1;
    left_node->height = max_height(left_node->left, left_node->right) + 1;

    return left_node;
}

/*
 * left_rotate(): left rotation of AVL tree node
 */
TREENODE *left_rotate(TREENODE *treenode) {
    TREENODE *right_node = treenode->right;
    TREENODE *right_left_node = right_node->left;

    right_node->left = treenode;
    treenode->right = right_left_node;

    treenode->height = max_height(treenode->left, treenode->right) + 1;
    right_node->height = max_height(right_node->left, right_node->right) + 1;

    return right_node;
}


