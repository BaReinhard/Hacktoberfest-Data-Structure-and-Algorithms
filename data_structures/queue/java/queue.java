import java.util.*;
public class queue{
    
    Scanner sc = new Scanner(System.in);
    int front=-1,rear=-1;
    int SIZE = 5;
    int queue[]=new int[SIZE];
        
    //System.out.println();
    void enQueue(int val){
        if(front == 0 && rear == SIZE-1){
            System.out.println("Queue is Full!");
        }
        else{
            if(front == -1){
                front = 0;
            }
            rear++;
            queue[rear]=val;
            System.out.println("Inserted : "+val);
        }
    }
    void deQueue(){
        int val;
        if(front == -1){
            System.out.println("Queue is Empty!");
        }
        else{
            val = queue[front];
            System.out.println("Deleted: "+val);
            front++;
            if(front >= rear){
                front = rear = -1;
            }
        }
    }
    
    void display() {
        int i;
        if (front == -1) 
        {
          System.out.println("Empty Queue");
        } 
        else 
        {
          System.out.println("\nFront index-> " + front);
          System.out.println("Items -> ");
          for (i = front; i <= rear; i++)
            System.out.print(queue[i] + "  ");
    
          System.out.println("\nRear index-> " + rear);
        }
    }
        
    public static void main(String args[]){
        queue q = new queue();
        q.deQueue();

        q.enQueue(1);
        q.enQueue(2);
        q.enQueue(3);
        q.enQueue(4);
        q.enQueue(5);
            
        q.enQueue(6);
    
        q.display();
    
        q.deQueue();
    
        q.display();
        
    }
}