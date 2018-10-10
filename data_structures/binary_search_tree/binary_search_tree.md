
## ELI5
A tree is a container that stores items in sorted order in memory.It's like the inversed version of an actual tree.

### Pros
* BSTs allow fast lookup, addition and removal of items.
### Cons
* Tree gets skewed to one side when we save sorted items.The advantage of fast operations is lost.

## Technical Explaination
Binary Search Tree is a node-based binary tree data structure.
*NODE: All items are stored in nodes.
*ROOT: The top node in a tree.
*CHILD: A node directly connected to another node when moving away from the Root.Each node can have 0 to 2 child nodes.Left child's value is smaller than its parent and right child's value is greater than its parent.
*LEAVES: Nodes with no child nodes.
*HEIGHT: Number of edges on the longest path between the root and a leaf.
*DEPTH: The depth of a node is the number of edges from the tree's root node to the node.

Storing 2,4,1,10,3 in a BST:
	2
   / \
  1   4
	 / \
	3  10
	  
	
### Pros
* Time Complexity of insertion,deletion and search is O(h). h=height of tree
i.e. O(log n) which is less than linked list and array.   n=number of nodes
### Cons
* For a skewed binary tree time complexity of insertion,deletion and search is O(n).
As for a skewed binary tree height h is O(n).
e.g 2,3,4,5
 2
  \
   3
    \
	 4
	  \
	   5
	
