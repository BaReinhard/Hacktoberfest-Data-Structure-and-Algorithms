#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int btree_insert(struct btree_node **root, void *item, unsigned int size, int (*compare_node)(const void*,const void*)) {
    // Insert the root    
    if (*root == NULL) {
        *root = malloc(sizeof(struct btree_node));
        if (!(*root)) {
            fprintf(stderr,"malloc() fail\n");
            return 0;
        }
        (*root)->left = (*root)->right = NULL;
        (*root)->item = malloc(size);
        if (!((*root)->item)) {
            fprintf(stderr,"malloc() fail\n");
            free(*root);
            return 0;
        }
        memcpy((*root)->item,item,size);
    } else {
        if (compare_node((*root)->item,item) > 0) {
            //Insert left
            btree_insert(&(*root)->left,item,size,compare_node);
        } else {
            //Insert right
            btree_insert(&(*root)->right,item,size,compare_node);
        }
    }
    return 1;
}

static void btree_free_node(struct btree_node *node) {
    free(node->item);
    free(node);
}

static struct btree_node* find_min_node(struct btree_node *node) {
    node = node->right;
    while (node) node = node->left;
    return node;
}

static struct btree_node* find_max_node(struct btree_node *node) {
    node = node->left;
    while (node) node = node->right;
    return node;
}

struct btree_node* btree_delete_node(struct btree_node *root, void *item, unsigned int size, int (*compare_node)(const void*,const void*)) {
    if (root == NULL) return root;
    else if (compare_node(item,root->item) < 0) root->left = btree_delete_node(root->left,item,size,compare_node);
    else if (compare_node(item,root->item) > 0) root->right = btree_delete_node(root->right,item,size,compare_node);
    else {
        // 1. Deleting a node with two children
        if ( root->left && root->right ) {
            struct btree_node *min_node = find_min_node(root);
            if (!min_node) {
                min_node = find_max_node(root);
            }
            memcpy(root->item,min_node->item,size);
            root->right = btree_delete_node(root->right,min_node->item,size,compare_node);
        } else if (root->left) {
            // 2. Deleting a node with one child (left)
            struct btree_node *node_delete = root;
            root = root->left;
            btree_free_node(node_delete);
        } else if (root->right) {
            // 2. Deleting a node with one child (right)
            struct btree_node *node_delete = root;
            root = root->right;
            btree_free_node(node_delete);
        } else {
            // 3. Deleting a leaf node
            btree_free_node(root);    
            root = NULL;
        }
    }
    return root; 
}

void btree_print(struct btree_node *root, void (*print_node)(const void *)) {
    if (root) {
        print_node(root->item);
        btree_print(root->left,print_node);
        btree_print(root->right,print_node);
    }
}

void btree_free(struct btree_node *root) {
    if (root) {
        free(root->item);
        btree_free(root->left);
        btree_free(root->right);
        free(root);
    }
}

int btree_search(struct btree_node *root, void *item, int (*compare_node)(const void*,const void*)) {
    if (root == NULL) return 0;
    else if (compare_node(item,root->item) > 0) return btree_search(root->right, item, compare_node);
    else if (compare_node(item,root->item) < 0) return btree_search(root->left, item, compare_node);
    else return 1;
}