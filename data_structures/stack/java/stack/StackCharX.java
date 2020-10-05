

/**
 *
 * @author Dilshan
 */
class StackCharX {
    
    private char[] stackArray;
    private int maxSize;
    private int top;
    
    
    public StackCharX(int x){
        maxSize = x;
        stackArray = new char[maxSize];
        top = -1;
    }
    
    public void push(char j){
        if(top == (maxSize-1)){
            System.out.println("Stack Is Full");
        }
        else{
            top = top + 1;
            stackArray[top] = j;
        }
    }
    
    public char pop(){
        if(top == -1){
            System.out.println("Stack Is Empty");
            return 999; 
        }
        else{
           return stackArray[top--];
        }
    }
    
    public double peek(){
        if(top == -1){
            System.out.println("Stack Is Empty");
            return 999; 
        }
        else{
            return stackArray[top];
        }
    }
    
    public boolean isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
    
    public boolean isFull(){
        if(top == maxSize-1){
            return true;
        }
        else{
            return false;
        }
    }
    
    
}
