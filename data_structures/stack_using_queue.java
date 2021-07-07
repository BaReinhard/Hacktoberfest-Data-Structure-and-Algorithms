import java.util.*;
 
/* Class stackUsingQueue */
class stackUsingQueue
{
    Queue<Integer> q ;
    Queue<Integer> tmp ;
 
    /* Constructor */
    public stackUsingQueue()
    {
        q = new LinkedList<Integer>();
        tmp = new LinkedList<Integer>();
    }    
    /*  Function to push an element to the stack */
    public void push(int data)
    {
        /* if no element is present in queue q then
         * enqueue the new element into q  */         
        if (q.size() == 0)
            q.add(data);
        else
        {
            /* if elements are present in q then
             * dequeue all the elements to 
             * temporary queue tmp */             
            int l = q.size();
            for (int i = 0; i < l; i++)
                tmp.add(q.remove());                
            /* enqueue the new element into q */
            q.add(data);        
            /* dequeue all the elements from
             * temporary queue tmp to q */                 
            for (int i = 0; i < l; i++)
                q.add(tmp.remove());
        }
    }    
    /*  Function to remove top element from the stack */
    public int pop()
    {
        if (q.size() == 0)
            throw new NoSuchElementException("Underflow Exception");        
        return q.remove();
    }    
    /*  Function to check the top element of the stack */
    public int peek()
    {
        if (q.size() == 0)
            throw new NoSuchElementException("Underflow Exception");            
        return q.peek();
    }        
    /*  Function to check if stack is empty */
    public boolean isEmpty()
    {
        return q.size() == 0 ;
    }
    /*  Function to get the size of the stack */
    public int getSize()
    {
        return q.size();
    }    
    /*  Function to display the status of the stack */
    public void display()
    {
        System.out.print("\nStack = ");
        int l = getSize();
        if (l == 0)
            System.out.print("Empty\n");
        else
        {
            Iterator it = q.iterator();
            while (it.hasNext())
                System.out.print(it.next()+" ");
            System.out.println();
        }
    }
}
/*  Class StackImplementUsingTwoQueues  */
public class StackImplementUsingTwoQueues
{    
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);      
        stackUsingQueue suq = new stackUsingQueue();                  
        /* Perform Stack Operations */          
        System.out.println("Stack Using Two Queues Test\n");  
        char ch;     
        do 
        {
            System.out.println("\nStack Operations");
            System.out.println("1. push");
            System.out.println("2. pop");
            System.out.println("3. peek");
            System.out.println("4. check empty");
            System.out.println("5. size");            
            int choice = scan.nextInt();
            switch (choice) 
            {
            case 1 : 
                System.out.println("Enter integer element to push");
                suq.push( scan.nextInt() );                 
                break;                          
            case 2 : 
                try
                {
                    System.out.println("Popped Element = "+ suq.pop() );
                }
                catch (Exception e)
                {
                    System.out.println("Error : " + e.getMessage());
                }        
                break;                         
            case 3 : 
                try
                {
                    System.out.println("Peek Element = "+ suq.peek() );
                }
                catch (Exception e)
                {
                    System.out.println("Error : " + e.getMessage());
                }
                break;                         
            case 4 : 
                System.out.println("Empty status = "+ suq.isEmpty() );
                break;                
            case 5 : 
                System.out.println("Size = "+ suq.getSize() ); 
                break;            
            default :  
                System.out.println("Wrong Entry \n ");
                break;
            }                 
            /* Display Stack */        
            suq.display();            
            System.out.println("\nDo you want to continue (Type y or n) \n");
            ch = scan.next().charAt(0);            
        } while (ch == 'Y'|| ch == 'y');                 
    }
}