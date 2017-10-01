/**
  A simple BST in C++
  Author: PryDt
*/

#ifndef BST_H
#define BST_H

#include <iostream>

template <class T>
class BinarySearchTree {
 public:
  // constructor
  BinarySearchTree() { root = nullptr; }
  ~BinarySearchTree()
  {
    destroy(root);
  }

  // insert
  void insert(T data) { insert(data, root); }

  // find min
  int findMin() { return findMin(root); }

  // remove node
  void remove(T data) { remove(data, root); }


  // check if a number is in tree
  bool find(T data)
  {
    return find(data, root);
  }

  // print tree in order out to stdout
  void printTree()
  {
    std::cout << "[ ";
    print(root);
    std::cout << " ]\n";
  }

 private:
  // basic building block of tree
  struct Node {
    T key;  // value of node

    Node *left;   // smaller
    Node *right;  // greater
  };

  void destroy(Node *n)
  {
    if(n == nullptr)
      return;

    destroy(n->left);
    destroy(n->right);

    delete n;
  }

  // helper function print
  void print(Node *ptr)
  {
    if (root != nullptr) {
      if (ptr->left != nullptr) {
        print(ptr->left);
      }
      std::cout << ptr->key << " ";

      if (ptr->right != nullptr) {
        print(ptr->right);
      }
    }
    else {
      std::cout << "Binary Search Tree is empty\n";
    }
  }

  // internals for find function
  bool find(T data, Node *n)
  {
    if(data == n->key)
      return true;

    if(data > n->key && n->right != nullptr)
      return find(data, n->right);

    if(data < n->key && n->left != nullptr)
      return find(data, n->left);

    return false;
  }

  // find min
  int findMin(Node *ptr)
  {
    if (root == nullptr) {
      std::cout << "findMin(): BST is empty\n";
      return -324243;
    }
    else {
      if (ptr->left != nullptr) {
        return findMin(ptr->left);
      }
      else {
        return ptr->key;
      }
    }
  }

  // make a new node
  Node *createLeaf(T data)
  {
    Node *n = new Node();
    n->key = data;

    n->left = nullptr;
    n->right = nullptr;

    return n;
  }

  void insert(T data, Node *ptr)
  {
    if (root == nullptr) {
      root = createLeaf(data);
      return;
    }
    else if (data < ptr->key) {
      if (ptr->left != nullptr)
        insert(data, ptr->left);
      else {
        ptr->left = createLeaf(data);
        return;
      }
    }
    else if (data > ptr->key) {
      if (ptr->right != nullptr)
        insert(data, ptr->right);
      else {
        ptr->right = createLeaf(data);
        return;
      }
    }
    else {
      std::cout << "Attempted to add duplicate key in BST\n";
    }
  }

  // remove match
  void removeMatch(Node *parent, Node *match, bool left)
  {
    if (root != nullptr) {
      Node *delptr;
      int small;

      // case A: 0 children
      if (match->left == nullptr && match->right == nullptr) {
        delptr = match;

        left ? parent->left = nullptr : parent->right = nullptr;

        delete delptr;
      }

      // case B: 1 child
      else if ((match->left == nullptr) != (match->right == nullptr)) {
        (left) ? ((match->right != nullptr) ? parent->left = parent->right : parent->left = parent->left)
          : (match->right != nullptr ? parent->right = match->right : parent->right = match->left);

        (match->right != nullptr) ? match->right = nullptr : match->left = nullptr;

        delptr = match;

        delete delptr;
      }

      // case C: 2 children
      else
      {
        small = findMin(match->right);
        remove(small, match);
        match->key = small;
      }

    }
    else {
      std::cout << "removeMatch(): cannot remove match, BST empty\n";
    }
  }

  // removes root of tree (used in special cases)
  void removeRootMatch()
  {
    if (root == nullptr) {
      std::cout << "removeRootMatch(): BST is empty\n";
      return;
    }

    Node *delptr = root;
    int small;

    // case A: 0 children
    if (root->left == nullptr && root->right == nullptr) {
      root = nullptr;
      delete delptr;
    }

    // case B: 1 child
    else if ((root->left == nullptr) != (root->right == nullptr)) {
      root = (root->left != nullptr) ? root->left : root->right;

      (root->right != nullptr) ? delptr->right = nullptr : delptr->left = nullptr;
      delete delptr;
    }

    // case C: 2 children

    else {
      small = findMin(root->right);
      remove(small, root);

      root->key = small;
    }
  }

  void remove(T data, Node *parent)
  {
    if (root == nullptr) {
      std::cout << "remove(): FAILED, BST is empty\n";
    }
    else {
      if (root->key == data) {
        removeRootMatch();
      }
      else {
        if (data < parent->key && parent->left != nullptr) {
          parent->left->key == data ? removeMatch(parent, parent->left, true)
                                    : remove(data, parent->left);
        }
        else if (data > parent->key && parent->right != nullptr) {
          parent->right->key == data ? removeMatch(parent, parent->right, false)
                                     : remove(data, parent->right);
        }
        else {
          std::cout << "remove(): The key(" << data
                    << ") was not found in BST\n";
        }
      }
    }
  }

  // root of the tree
  Node *root;
};

// typedef for convenience
typedef BinarySearchTree<int> intBST;

#endif // BST_H
