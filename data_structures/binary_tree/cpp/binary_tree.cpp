#include <iostream>

struct Node {
    int key;
    Node *leftnode;
    Node *rightnode;
    std::string value;
    Node(int tkey, const std::string& tvalue) : leftnode(nullptr), rightnode(nullptr), key(tkey), value(tvalue) {}
};

Node root_node(1, "Node #1"); 
std::string query_bst(const int key) {
    Node *cur_node = &root_node;
    while (cur_node != nullptr) {
        if (key == cur_node->key) {
            return cur_node->value;
        }
        if (key < cur_node->key) { 
            cur_node = cur_node->leftnode;
        } else {
            cur_node = cur_node->rightnode;
        }
    }
    return ""; 
}

void insert_bst(int key, const std::string& value) {
    Node *cur_node;
    Node *next_node = &root_node;
    while (next_node != nullptr) {
        cur_node = next_node;
        if (key < cur_node->key) {
            next_node = cur_node->leftnode;
        } else {
            next_node = cur_node->rightnode;
        }
    }
    if (key < cur_node->key) {
        cur_node->leftnode = new Node(key, value);
    }
    else {
        cur_node->rightnode = new Node(key, value);
    }
}

int main() {
    insert_bst(2, "Node #2");
    insert_bst(3, "Node #3");
    std::cout << query_bst(3) << '\n';
}
