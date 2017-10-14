#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Data structures
struct treenode
{
  int data;
  bool is_red;
  struct treenode *left;
  struct treenode *right;
};

// Type definitions
typedef struct treenode TREENODE;
typedef TREENODE *TREE;

// Function prototypes
TREE make_tree(int data, TREE left, TREE right);
int is_empty(TREE t);
TREE left_subtree(TREE t);
TREE right_subtree(TREE t);
size_t size(TREE t);
size_t height(TREE t);
void preorder(TREE t);
void inorder(TREE t);
void postorder(TREE t);
void print_leaf(TREE t);
void insert_RB(TREE *t, int data);
int search_RB(TREE t, int key);

int main()
{
  TREE t;
  int i;

  t = NULL; // let's start with an empty tree

  for (i = 1; i < 10; i++)
    insert_RB(&t, i);

  printf("Tree Size: %u / %u\n", size(t), height(t));

  printf("Pre-order traversal: ");
  preorder(t);
  printf("\n");

  printf("In-order traversal: ");
  inorder(t);
  printf("\n");

  printf("Post-order traversal: ");
  postorder(t);
  printf("\n");

  printf("Leaf Node: ");
  print_leaf(t);
  printf("\n");
  // ***** END OF EXAMPLE ***** //

  exit(EXIT_SUCCESS);
}

TREE make_tree(int data, TREE left, TREE right)
{
  TREE t;

  t = (TREE) malloc(sizeof(TREENODE));
  t->data = data;
  t->left = left;
  t->right = right;
  t->is_red = true;

  return t;
}

bool is_red(TREE t)
{
  if (t == NULL)
    return false;
  else
    return t->is_red;
}

int is_empty(TREE t)
{
  return (t == NULL);
}

TREE left_subtree(TREE t)
{
  return t->left;
}

TREE right_subtree(TREE t)
{
  return t->right;
}

size_t size(TREE t)
{
  // Basis: return 0 if tree is empty
  if (is_empty(t))
    return 0;

  // Recursive: Count the root and accumulate size of left and right subtrees
  else
    return 1 + size(left_subtree(t)) + size(right_subtree(t));
}

size_t max(size_t x, size_t y)
{
  if (x > y)  return x;
  else return y;
}

size_t height(TREE t)
{
  // Basis: return 0 if tree is empty
  if (is_empty(t))
    return 0;

  // Recursive: +1 Current layer and find maximum height of both left and right
  return 1 + max(height(left_subtree(t)), height(right_subtree(t)));
}

void preorder(TREE t)
{
  if (!is_empty(t))
  {
    printf("%d ", t->data);
    preorder(left_subtree(t));
    preorder(right_subtree(t));
  }
}

void inorder(TREE t)
{
  if (!is_empty(t))
  {
    inorder(left_subtree(t));
    printf("%d ", t->data);
    inorder(right_subtree(t));
  }
}

void postorder(TREE t)
{
  if (!is_empty(t))
  {
    postorder(left_subtree(t));
    postorder(right_subtree(t));
    printf("%d ", t->data);
  }
}

void print_leaf(TREE t)
{
  if (!is_empty(t))
  {
    print_leaf(left_subtree(t));

    // The leaf has no children
    if ((left_subtree(t) == NULL) && (right_subtree(t) == NULL))
      printf("%d ", t->data);

    print_leaf(right_subtree(t));
  }
}

void rotate_left(TREE *t)
{
  TREE old_root, new_root;

  old_root = *t;
  new_root = (*t)->right;

  old_root->right = new_root->left;
  new_root->left = old_root;
  new_root->is_red = old_root->is_red;
  old_root->is_red = true;

  *t = new_root;
}

void rotate_right(TREE *t)
{
  TREE old_root, new_root;

  old_root = *t;
  new_root = (*t)->left;

  old_root->left = new_root->right;
  new_root->right = old_root;
  new_root->is_red = old_root->is_red;
  old_root->is_red = true;

  *t = new_root;
}

void flip_color(TREE *t)
{
  (*t)->is_red = !(*t)->is_red;
  (*t)->left->is_red = !(*t)->left->is_red;
  (*t)->right->is_red = !(*t)->right->is_red;
}

void insert_RB(TREE *t, int data)
{
  if (is_empty(*t))
    *t = make_tree(data, NULL, NULL);
  else if ((*t)->data > data)
    insert_RB(&((*t)->left), data);
  else if ((*t)->data < data)
    insert_RB(&((*t)->right), data);
  else
    ; // No duplicates !!

  // Red node should be on left
  if (is_red((*t)->right) && !is_red((*t)->left)) rotate_left(t);

  // Consecutive red nodes must be rotated to be double red children and flipped
  if (is_red((*t)->left) && is_red((*t)->left->left)) rotate_right(t);

  // No double red children, flip color !!
  if (is_red((*t)->left) && is_red((*t)->right)) flip_color(t);
}

int search_RB(TREE t, int key)
{
  // Basis 1: there is no data if tree is empty
  if (is_empty(t))
    return 0;

  // Basis 2: if the root node is the key, we found it
  else if (t->data == key)
    return 1;

  // Recursive 1: if the root is greather, the key should be on the left of BST
  else if (t->data > key)
    return search_RB(left_subtree(t), key);

  // Recursive 2: the key should be on the right subtree otherwise
  else
    return search_RB(right_subtree(t), key);
}
