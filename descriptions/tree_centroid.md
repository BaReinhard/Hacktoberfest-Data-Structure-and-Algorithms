## ELI5
Centroid of a undirected tree: Size of every subtree is no more than half of the tree's size.
Depth of the centroid tree is O( log n )
We can find the centroid in O( n ) 
USES:Centroid decomposition
### Pros
* Reform a undirected tree in a balanced form.
### Cons
* Doesn't work in a directed tree.
## Technical Explaination
* Time Complexity: 
1. select arbitrart node: O(1)
2. DFS: O(n)
3. reposition to v: O(1)
4. find centroid: O(n)
