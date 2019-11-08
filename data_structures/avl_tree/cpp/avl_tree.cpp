#include <iostream>
using namespace std;

/*
Class for defining a node in binary search tree
Has -
int val 	  - Value of the node
node * left   - Pointer to the left node
node * right  - Pointer to the right node
int heighe	  - Height of the node
*/
class node {
	public:
	/*
	Constructor for node
	Parameters:
	int v - sets value of node to v.
	 */

	explicit node(int v) {
		this->val = v;
		this->left = NULL;
		this->right = NULL;
		this->height = 1;
	}

	/*
	Getter functions
	*/
	int get_val() {
		return val;
	}

	node * get_left() {
		return left;
	}

	node * get_right() {
		return right;
	}

	int get_height() {
		return height;
	}

	/*
	Function to return balance factor of a node

	Parameters:
	node * t  -  Pointer to node

	Returns:
	int : balance factor of node t.
	*/
	int get_bal_fact() {
		int ht_lt = get_left() ? get_left()->get_height() : 0;
		int ht_rt = get_right() ? get_right()->get_height() : 0;
		return (ht_lt-ht_rt);
	}

	/*
	Function to right rotate the node

	Parameters:
	none

	Returns:
	node * : Pointer to node which becomes the parent after rotation
	*/
	node * right_rotate() {
		if(this->get_left() == NULL) return this;
		node * lt = this->get_left();
		node * tmp = lt->get_right();
		lt->set_right(this);
		this->set_left(tmp);

		int ht_lt = this->get_left() ? this->get_left()->get_height() : 0;
		int ht_rt = this->get_right() ? this->get_right()->get_height() : 0;

		this->set_height(max(ht_lt, ht_rt) + 1);

		int ht_lt_1 = lt->get_left() ? lt->get_left()->get_height() : 0;
		int ht_rt_1 = lt->get_right() ? lt->get_right()->get_height() : 0;

		lt->set_height(max(ht_lt_1, ht_rt_1) + 1);

		return lt;
	}

	/*
	Function to left rotate the node

	Parameters:
	none

	Returns:
	node * : Pointer to node which becomes the parent after rotation
	*/
	node * left_rotate() {
		if(this->get_right() == NULL) return this;
		node * rt = this->get_right();
		node * tmp = rt->get_left();

		rt->set_left(this);
		this->set_right(tmp);


		int ht_lt = this->get_left() ? this->get_left()->get_height() : 0;
		int ht_rt = this->get_right() ? this->get_right()->get_height() : 0;

		this->set_height(max(ht_lt, ht_rt) + 1);

		int ht_lt_1 = rt->get_left() ? rt->get_left()->get_height() : 0;
		int ht_rt_1 = rt->get_right() ? rt->get_right()->get_height() : 0;

		rt->set_height(max(ht_lt, ht_rt) + 1);

		return rt;
	}


	/*
	Setter functions
	*/
	void set_val(int v) {
		this->val = v;
	}

	void set_left(node * l) {
		this->left = l;
	}

	void set_right(node * r) {
		this->right = r;
	}

	void set_height(int h) {
		this->height = h;
	}

	private:
	int val;
	node * left;
	node * right;
	int height;
};


/*
Class for defining AVL tree

Has -
node * root - Node pointer to the root of the tree
*/
class AVL {
	public:
	/*
	Class' public member functions
	*/
	AVL() {
		this->root = NULL;
	}

	/*
	Function to search a key

	Parameters:
	int v - integer value to search in tree

	Returns:
	node * : Pointer to node having val v
	*/
	node * search(int v) {
		return search_util(root, v);
	}

	/*
	Function to insert a key

	Parameters:
	int v - integer value to insert in tree

	Returns:
	nothing
	*/
	void insert(int v) {
		root = insert_util(root, v);
	}

	/*
	Function for inorder traversal

	Parameters:
	none

	Returns:
	nothing
	*/
	void inorder_traversal() {
		inorder_util(root);
	}


	/*
	Function for preorder traversal

	Parameters:
	none

	Returns:
	nothing
	*/
	void preorder_traversal() {
		preorder_util(root);
	}


	/*
	Function for postorder traversal

	Parameters:
	none

	Returns:
	nothing
	*/
	void postorder_traversal() {
		postorder_util(root);
	}


	/*
	Function to delete a key

	Parameters:
	int v - integer value to delete from tree

	Returns:
	nothing
	*/
	void delete_node(int v) {
		root = delete_node_util(root, v);
	}

	private:
	node * root;

	/*
	Class' private member functions
	*/


	/*
	Utility Function to search a key for a subtree

	Parameters:
	node * t - pointer to root of the tree
	int v	 - integer value to search in tree

	Returns:
	node * : Pointer to node having val v
	*/
	node * search_util(node * t, int v) {
		if(t == NULL || t->get_val() == v) return t;
		else if (v < t->get_val())
			return search_util(t->get_left(), v);
		else
			return search_util(t->get_right(), v);
	}

	/*
	Utility Function to insert a key in a subtree

	Parameters:
	node * t - pointer to root of the tree
	int v	 - integer value to insert in tree

	Returns:
	node * : Pointer to node having val v
	*/
	node * insert_util(node * t, int v) {
		if(t == NULL) return new node(v);

		if(v < t->get_val()) {
			t->set_left(insert_util(t->get_left(), v));
		} else if (v > t->get_val()) {
			t->set_right(insert_util(t->get_right(), v));
		} else {
			return t;
		}


		int ht_lt = t->get_left() ? t->get_left()->get_height() : 0;
		int ht_rt = t->get_right() ? t->get_right()->get_height() : 0;

		t->set_height(max(ht_lt, ht_rt) + 1);
		int bf = t->get_bal_fact();
		// cout << "bf of " << t->get_val() << " is : " << bf << "\n";
		// Skewed from left
		if(bf > 1) {
			if(v < t->get_left()->get_val()) {
				return t->right_rotate();
			} else if (v > t->get_left()->get_val()) {
				t->set_left(t->get_left()->left_rotate());
				return t->right_rotate();
			}
		}

		// Skewed from right
		if(bf < -1) {
			if(v > t->get_right()->get_val()) {
				return t->left_rotate();
			} else if (v < t->get_right()->get_val()) {
				t->set_right(t->get_right()->right_rotate());
				return t->left_rotate();
			}
		}

		return t;
	}


	/*
	Utility Function for inorder traversal

	Parameters:
	node * t - Pointer to root of tree

	Returns:
	nothing
	*/
	void inorder_util(node * t) {
		if(t != NULL) {
			inorder_util(t->get_left());
			cout << t->get_val() << "\n";
			inorder_util(t->get_right());
		}
	}

	/*
	Utility Function for preorder traversal

	Parameters:
	node * t - Pointer to root of tree

	Returns:
	nothing
	*/
	void preorder_util(node * t) {
		if(t != NULL) {
			cout << t->get_val() << "\n";
			preorder_util(t->get_left());
			preorder_util(t->get_right());
		}
	}

	/*
	Utility Function for postorder traversal

	Parameters:
	node * t - Pointer to root of tree

	Returns:
	nothing
	*/
	void postorder_util(node * t) {
		if(t != NULL) {
			postorder_util(t->get_left());
			postorder_util(t->get_right());
			cout << t->get_val() << "\n";
		}
	}


	/*
	Function to find maximum value node in a tree

	Parameters:
	node * t - pointer to root node

	Returns:
	node *	- pointer to maximum value node
	*/
	node * max_node(node * t) {
		if(t == NULL) return t;

		node * curr = t;
		while(curr->get_right())
			curr = curr->get_right();
		return curr;
	}

	/*
	Utility Function to delete a key from a subtree

	Parameters:
	node * t - pointer to root of the tree
	int v	 - integer value to delete in tree

	Returns:
	node * : pointer t
	*/

	node * delete_node_util(node * t, int v) {
		if (t == NULL) return t;

		else if (v < t->get_val())	t->set_left(delete_node_util(t->get_left(), v));
		else if (v > t->get_val())	t->set_right(delete_node_util(t->get_right(), v));

		// Case where t->get_val() == v
		// This is the node to be deleted.
		else {	// Ignore CPPLintBear
			// There can be following cases:
			// 1) Node has No child or 1 child
			// 2)  Node has No child or 1 child

			// Case 1 -  Node has No child or 1 child
			if(t->get_left() == NULL) {
				node * tmp = t->get_right();
				free(t);
				return tmp;
			} else if (t->get_right() == NULL) {
				node * tmp = t->get_left();
				free(t);
				return tmp;
			}

			// Case 2 -  Node has No child or 1 child

			// Find inorder predecessor
			node * tmp = max_node(t->get_left());

			// set the value
			t->set_val(tmp->get_val());

			// delete the predecessor
			t->set_left(delete_node_util(t->get_left(), tmp->get_val()));
		}

		if (t == NULL) return t;

		int ht_lt = t->get_left() ? t->get_left()->get_height() : 0;
		int ht_rt = t->get_right() ? t->get_right()->get_height() : 0;

		t->set_height(max(ht_lt, ht_rt) + 1);
		int bf = t->get_bal_fact();

		if(bf > 1) {
			if(t->get_left()->get_bal_fact() >=0) {
				return t->right_rotate();
			} else if (t->get_left()->get_bal_fact() < 0) {
				t->set_left(t->get_left()->left_rotate());
				return t->right_rotate();
			}
		}

		// Skewed from right
		if(bf < -1) {
			if(t->get_left()->get_bal_fact() <= 0) {
				return t->left_rotate();
			} else if (t->get_left()->get_bal_fact() > 0) {
				t->set_right(t->get_right()->right_rotate());
				return t->left_rotate();
			}
		}

		return t;
	}
};


int main() {
	AVL b;
	// {1, 2, 9, 293, 41, 15, 52, 3, 121, 7, 1223, 3449, 15, 1 };
	b.insert(1);
	b.insert(2);
	b.insert(9);
	b.insert(293);
	b.insert(41);
	b.insert(15);
	b.insert(52);
	b.insert(3);
	b.insert(121);
	b.insert(7);
	b.insert(3449);
	b.insert(1223);
	b.insert(15);
	b.insert(0);
	b.insert(-1);

	cout << "Traversals of Tree after inserting values: \n";
	cout << "{1, 2, 9, 293, 41, 15, 52, 3, 121, 7, 1223, 3449, 15, 1}\n";

	cout << "Preorder traversal:\n";
	b.preorder_traversal();

	cout << "Inorder traversal:\n";
	b.inorder_traversal();

	cout << "Postorder traversal:\n";
	b.postorder_traversal();


	int search_key = 52;

	node * t = b.search(search_key);
	if(t != NULL) {
		cout << "Key value " << search_key << " is present in tree.\n";
	} else {
		cout << "Key value " << search_key << " is NOT present in tree.\n";
	}

	b.delete_node(52);
	b.delete_node(121);
	b.delete_node(293);

	cout << "Deleting values: 52, 121, 293 from the tree.\n";

	t = b.search(search_key);
	if(t != NULL) {
		cout << "Key value " << search_key << " is present in tree.\n";
	} else {
		cout << "Key value " << search_key << " is NOT present in tree.\n";
	}

	cout << "Traversals of Tree after deleting values: 52, 121, 293.\n";

	cout << "Preorder traversal:\n";
	b.preorder_traversal();

	cout << "Inorder traversal:\n";
	b.inorder_traversal();

	cout << "Postorder traversal:\n";
	b.postorder_traversal();

	return 0;
}
