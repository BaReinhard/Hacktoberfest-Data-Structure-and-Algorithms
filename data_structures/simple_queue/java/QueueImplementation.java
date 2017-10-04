import java.util.Scanner;

/* Class QueueImplement  */
public class QueueImplementation
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);

        System.out.println("Array Queue Test\n");
        System.out.println("Enter Size of Integer Queue ");
        int n = scan.nextInt();
        /* creating object of class arrayQueue */
        arrayQueue q = new arrayQueue(n);        
        /* Perform Queue Operations */
        char ch;
        do{
            System.out.println("\nQueue Operations");
            System.out.println("1. insert");
            System.out.println("2. remove");
            System.out.println("3. peek");
            System.out.println("4. check empty");
            System.out.println("5. check full");
            System.out.println("6. size");
            int choice = scan.nextInt();
            switch (choice)
            {
                case 1 :
                    System.out.println("Enter integer element to insert");
                    try
                    {
                        q.insert( scan.nextInt() );
                    }
                    catch(Exception e)
                    {
                        System.out.println("Error : " +e.getMessage());
                    }
                    break;
                case 2 :
                    try
                    {
                        System.out.println("Removed Element = "+q.remove());
                    }
                    catch(Exception e)
                    {
                        System.out.println("Error : " +e.getMessage());
                    }
                    break;
                case 3 :
                    try
                    {
                        System.out.println("Peek Element = "+q.peek());
                    }
                    catch(Exception e)
                    {
                        System.out.println("Error : "+e.getMessage());
                    }
                    break;
                case 4 :
                    System.out.println("Empty status = "+q.isEmpty());
                    break;
                case 5 :
                    System.out.println("Full status = "+q.isFull());
                    break;
                case 6 :
                    System.out.println("Size = "+ q.getSize());
                    break;
                default : System.out.println("Wrong Entry \n ");
                    break;
            }
            /* display Queue */
            q.display();
            System.out.println("\nDo you want to continue (Type y or n) \n");
            ch = scan.next().charAt(0);

        } while (ch == 'Y'|| ch == 'y');
    }
}