#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

int main() {
    TREENODE *root = NULL;

    root = insert(root, create_node(9));
    root = insert(root, create_node(5));
    root = insert(root, create_node(10));
    root = insert(root, create_node(0));
    root = insert(root, create_node(6));
    root = insert(root, create_node(11));
    root = insert(root, create_node(-1));
    root = insert(root, create_node(1));
    root = insert(root, create_node(2));

    pre_order(root);
    fprintf(stdout, "\n");
    root = delete(root, 9);
    pre_order(root);
    fprintf(stdout,"\n");

    return EXIT_SUCCESS;
}


