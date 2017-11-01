## ELI5
An unrolled linked list is a hybrid of a list and an array that tries to provide the strengths of both, while minimizing their weaknesses.

USES: General-purpose sequence data structure that is easy to implement and relatively efficient.
### Pros
* Indexing and iteration is typically faster than a linked list.
* Typically takes up less space than a linked list.


### Cons 
* In the worst case (degenerate, unbalanced list) it's performance is as bad or worse than a linked list.


## Technical Explanation

An unrolled linked list is a linked list of arrays.  Each array in the list can contain up to M elements.  This spreads the overhead of the links (pointers) over up to M elements, which makes it more space efficient than a list.
It also utilizes caching better, as each link/pointer dereference pulls M elements into cache, versus a single element for a typical linked list.
This can make it faster for iteration as well as indexing.

In the worst case, where the list is unbalanced and each bucket only contains a single element, it becomes as slow as a standard linked list.

An implementation should rebalance its subarrays on modification to maintain good performance.
