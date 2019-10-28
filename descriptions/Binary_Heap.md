## Binary Heap
A binary heap is a complete binary tree which satisfies the heap ordering property. The ordering can be one of two types: the min-heap property: the value of each node is greater than or equal to the value of its parent, with the minimum-value element at the root.

### Pros and Cons:
Storing data on the heap is slower than it would take when using the stack. However, the main advantage of using the heap is its flexibility. Thats because memory in this structure can be allocated and remove in any particular order. Slowness in the heap can be compensated if an algorithm was well designed and implemented. 

## TECHNICAL EXPLAINATION
Heap Data Structure is generally taught with Heapsort. Heapsort algorithm has limited uses because Quicksort is better in practice. Nevertheless, the Heap data structure itself is enormously used. Following are some uses other than Heapsort.

Priority Queues: Priority queues can be efficiently implemented using Binary Heap because it supports insert(), delete() and extractmax(), decreaseKey() operations in O(logn) time. Binomoial Heap and Fibonacci Heap are variations of Binary Heap. These variations perform union also in O(logn) time which is a O(n) operation in Binary Heap. Heap Implemented priority queues are used in Graph algorithms like Prim’s Algorithm and Dijkstra’s algorithm.

Order statistics: The Heap data structure can be used to efficiently find the kth smallest (or largest) element in an array. See method 4 and 6 of this post for details.





