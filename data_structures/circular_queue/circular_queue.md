## ELI5
CIRCULAR QUEUE is a queue in which last position is connected back to first position,i.e. after last location of the list we visit the first location.Forms a circle.

### Pros:
* Fast operations of adding and removing elements.
* Utilizes memory efficiently.

### Cons:
* May become a never-ending loop.

## TECHNICAL EXPLAINATION
A FIFO data structure ,also called ‘Ring Buffer’,where last element points back to the first element to make a circle.
* Operations on Circular Queue:.
	*enqueue(element): This function is used to insert an element into the circular queue. The new element is always inserted at Rear position.
	Steps:
	Check whether queue is Full – Check ((REAR == SIZE && FRONT == 1) || (REAR == FRONT-1)) If TRUE,queue is full. If queue is not full then insert element.
	*dequeue(): This function is used to delete an element from the circular queue.The element is always deleted from FRONT position.
eg. CQueue = 1,2,3,4,_
enqueue(5) gives CQueue=1,2,3,4,5
dequeue() gives CQueue= _,2,3,4,5
enqueue(6) gives CQueue=6,2,3,4,5

### Pros:
* Time complexity of enqueue(), dequeue() operation is O(1).
* Prevents wastage of space of Simple Queue.

### Cons:
* A circular queue might cause an an infinite loop, impairing processing - if not implemented properly or in a multi-threaded environment. 
* Complex to code.
