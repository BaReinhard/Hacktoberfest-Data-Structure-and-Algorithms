
## ELI5

Stack behaves like a real-world stack, for example – a deck of cards or a pile of plates, etc.Stack allows operations at one end only,i.e. at top.
The element inserted last is accessed first.

### Pros

* Last in, first out fashion of accessing data is possible.
*Data cannot be corrupted as nobody can easily insert data in middle. 

### Cons

*Limited memory.
*Cannot access elements randomly,the top element will be accessed first. 

## Technical Explaination

A stack is an abstract data type that serves as a collection of elements, with two principal operations:
### Push
Adds an element to the collection at the 'top+1' position.
### Pop
Removes the most recently added element that was not yet removed from 'top'.
Its a LIFO(Last In First Out) data structure.

EXAMPLE:
If we have STACK -  10
					20
					40
1. push(50) gives:
STACK - 50
		10
		20
		40
2. pop() gives:
STACK - 10
		20
		40

USES:
1.Expression evaluation and syntax parsing.
2.Backtracking.
3.Compile time memory management
and,Several other algorithms.

### Pros

* Helps manage the data in particular way (LIFO) which is not possible with Linked list and array.
* When function is called the local varriables are stored in stack and destroyed once returned. Stack is used when varriable is not used outside the function.
So, it gives control over how memory is allocated and deallocated
* Not easily corrupted.

### Cons

*Stack memory is limited.Overflow otherwise.
*Creating too many objects on the stack will increase the chances of stack overflow.
*Random access isn't possible.
