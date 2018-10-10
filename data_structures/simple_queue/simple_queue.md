## ELI5
QUEUE: Queue is a list of elements where elements are removed in the order they were added. First come, first serve basis like in actual queues at ticket counters.
USE: Used when we want to process items in a first in,first out order.

### Pros
* Fast to add and remove items from the list.
### Cons
* Searching a queue is difficult.
* Wastage of space/memory when front items have been removed.

## Technical Explaination
A queue or FIFO (first in, first out) is an abstract data type(ADT) that serves as a collection of elements on which we perform these main operations:
* enqueue: Adding element to queue
* deque: Extracting element from queue
Two pointer variables : FRONT and REAR
FRONT of a queue points to the first element that will be dequed and REAR is pointer the last element of the queue.
For a queue = 8,4,5,6,7,_. (FRONT=1,REAR=5)
enqueue(0) gives queue = 8,4,5,6,7,0.    (REAR = REAR+1)(FRONT =1,REAR=6)
dequeue() gives queue  = _,4,5,6,7,0.    (FRONT = FRONT +1)(FRONT=2,REAR=6)
First element of queue is removed from queue and returned via dequeue.
USE: Used when multiple processes are waiting for a resourse.e.g. Disk scheduliing.
### Pros
*Time complexity of all operations like enqueue(), dequeue(), isFull(), isEmpty(), front() and rear() is O(1)
* It can be implemented by using both array and linked list.


### Cons
* Not readily searchable.
* Wastage of memory space.Once queue becomes full, we can not insert the next element even if there is a space in front of queue.
i.e. For N size queue.After N insertions REAR points to N. When queue is dequed(<=N) times then FRONT = i. Now, enqueue will add items at REAR+1 only and since size is N, no new insertions take place even though queue has few elements.
WE USE CIRCULAR QUEUE TO SAVE MEMORY SPACE.
