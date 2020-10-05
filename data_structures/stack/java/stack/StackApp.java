
/**
 *
 * @author Dilshan
 */
public class StackApp {
    
    public static void main(String ar[]){
        
        StackX myStack = new StackX(10);
        myStack.push(10);
        myStack.push(50);
        myStack.push(12);
        myStack.push(70);
        
        while(!myStack.isEmpty()){
            System.out.println(myStack.pop());
            System.out.println("");
        }
    }
}
