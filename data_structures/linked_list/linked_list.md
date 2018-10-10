## ELI5
A linked list is a data structure made up of a bunch of little boxes that each hold a piece of information and directions to the next box. This makes it easy to make changes, because you don't have to move anything to a different box, you just have to give each box new directions. However, if you want the values in a certain box, you have to ask every box before it for directions to get there.
### Pros
* It's cheap to add and remove elements from a linked list.
### Cons
* It's expensive to get values in a given box.

## Technical Explanation
A linked list is defined recursively as being either empty, or containing a node which stores a value and a pointer to a linked list. A linked list commonly starts with a pointer (often named "start" or "head") to the first node, and each subsequent node contains its value and a pointer to the next node. The pointer of the last node points to null, and therefore there are no more nodes and the list ends.
Because of the pointer connections between nodes, inserting and removing values from a linked list is efficient, in O(1) time. Whereas contiguous data structures require shifting every piece of data after the edit point to preserve the contiguous structure, one can simply redirect the pointers in a linked list to accomplish the same.
Inserting an item requires creating a node with that item, assigning that node's pointer to the address of the item after it (which can be retrieved from the item before it) and then assigning the pointer of the item before it to the newly created node. 
Deleting/erasing an item simply requires redirecting the pointer of the previous node to the next node. Care must be taken in languages where memory is manually deallocated/freed so as to delete the node before redirecting the pointer that points to it, and without losing the pointer to the next node. 
The pointer-based nature of list also makes it easier to make greater changes such as reversing the list, as once again no values must be copied to different spots in memory, instead only pointers are reassigned.
Accessing the value at a given index in the list is expensive, in O(n) time. One must start at a known pointer and increment through the list one node at a time until the desired location is reached. Because lists are not based on arrays, subscripting in the standard O(1) sense cannot be used to access list values.
### Pros
* Adding and removing nodes from the list is cheap O(1)
### Cons
* Accessing values in the list is expensive O(n)
