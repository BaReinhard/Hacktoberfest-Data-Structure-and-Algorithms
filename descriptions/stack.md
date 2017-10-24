Stack Data Structure

Stack is a linear data structure which follows a particular order in which the operations are performed. The order may be LIFO (Last in First Out). 
As an example take bunch of plates. If you are going to take a plate from that you have to get the bottom one which was added by last. This is a real world example about stack.

Basic operations are performed in the stack:
	Push: Adds an item in the stack. If the stack is full, then it is said to be an Overflow condition.
	Pop: Removes an item from the stack. The items are popped in the reversed order in which they are pushed. If the stack is empty, then it is said to be an Underflow condition.
    isEmpty: Returns true if stack is empty, else false.

Pros :
1. Helps manage the data in particular way (LIFO) which is not possible with Linked list and array.
2. When function is called the local variables are stored in stack and destroyed once returned. Stack is used when variable is not used outside the function.
So, it gives control over how memory is allocated and de-allocated.
3. Stack frees you from the burden of remembering to cleanup (read delete) the object.
4. Not easily corrupted (No one can easily inset data in middle).

Cons:
1. Stack memory is limited.
2. Creating too many objects on the stack will increase the chances of stack overflow.
3. Random access not possible.

Java program to implement basic stack

class StackExample
{
    static final int MAX = 500;
    int top;
    int a[] = new int[MAX]; 
 
    boolean isEmpty()
    {
        return (top < 0);
    }
    Stack()
    {
        top = -1;
    }
 
    boolean push(int x)
    {
        if (top >= MAX)
        {
            System.out.println("Stack Overflow");
            return false;
        }
        else
        {
            a[++top] = x;
            return true;
        }
    }
 
    int pop()
    {
        if (top < 0)
        {
            System.out.println("Stack Underflow");
            return 0;
        }
        else
        {
            int x = a[top--];
            return x;
        }
    }
}
 
class Main
{
    public static void main(String args[])
    {
        StackExample s = new StackExample( );
        s.push(10);
        s.push(20);
        s.push(30);
        System.out.println(s.pop() + " Popped from stack");
    }
}

