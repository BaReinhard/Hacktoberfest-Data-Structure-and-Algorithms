/*
 * Java Program to Implement Queue
 */

import java.util.*;

/*  Class arrayQueue  */
class ArrayQueue<T> {
    protected T queue[] ;
    protected int front, rear, size, len;

    /* Constructor */
    public ArrayQueue(int n)
    {
        size = n;
        len = 0;
        queue = new T[size];
        front = -1;
        rear = -1;
    }
    /*  Function to check if queue is empty */
    public boolean isEmpty()
    {
        return front == -1;
    }
    /*  Function to check if queue is full */
    public boolean isFull()
    {
        return front==0 && rear == size -1 ;
    }
    /*  Function to get the size of the queue */
    public int getSize()
    {
        return len ;
    }
    /*  Function to check the front element of the queue */
    public T peek()
    {
        if (isEmpty())
            throw new NoSuchElementException("Underflow Exception");
        return queue[front];
    }
    /*  Function to insert an element to the queue */
    public void insert(T i)
    {
        if (rear == -1)
        {
            front = 0;
            rear = 0;
            queue[rear] = i;
        }
        else if (rear + 1 >= size)
            throw new IndexOutOfBoundsException("Overflow Exception");
        else if ( rear + 1 < size)
            queue[++rear] = i;
        len++ ;
    }
    /*  Function to remove front element from the queue */
    public T remove()
    {
        if (isEmpty())
            throw new NoSuchElementException("Underflow Exception");
        else
        {
            len-- ;
            int ele = queue[front];
            if ( front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
                front++;
            return ele;
        }
    }
    /*  Function to display the status of the queue */
    public void display()
    {
        System.out.print("\nQueue = ");
        if (len == 0)
        {
            System.out.print("Empty\n");
            return ;
        }
        for (int i = front; i <= rear; i++)
            System.out.print(queue[i]+" ");
        System.out.println();
    }
}