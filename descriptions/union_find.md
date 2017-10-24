## ELI5
Union Find Data structure quickly figures out if there is a line joining two points or not! Imagine a maze full of different coloured lines and lots of points on each of these. Now, you want to figure out if point A and point B are on the same line or not, quickly, such that, you can also add more lines of the same colour at any time, quickly.

(Here, the lines are graph edges and points are graph nodes)

### Pros
* Fast query time 
* Best of both worlds - find points and add new lines
### Cons
* If you don't have to draw more lines, find time can be improved
* If you don't have to find points, line drawing time can be improved

## Technical Explaination
A Union Find Datastructure aims to achieve a balance between query and add operations, more specifically, querying if 2 nodes belong to the same set and creating union of 2 or more sets. The way this works is, you initially have n disjoint sets representing the n initial points in the datastructure. Representation is via a pointer array, with the pointer for each indexed element pointing to itself. So, the pointer for the k'th element points to itself, k.

1  2  3  4
^  ^  ^  ^
|  |  |  |
1  2  3  4

Once we do a union operation, we make the parent pointer of A set point to B set.

So, union(4,3) means

1  2  3  4
^  ^  ^  
|  |  | \
1  2  3  4

For find, we find the parent pointers and check if they are the same. If yes, they are in the same set, if no, they aren't.

This is used majorly to find if there exists a cycle in a graph. ( As a part of Prims and Krustkals Algorithm to find the M.S.T)

### Pros
* Find is O(log*N) where N is number of elements. This is almost O(1) for all practical purposes. Achieved by using path compression and union by size as added enhancements to the base algorithm.
### Cons
* Only applies to a very specific set of problems.
