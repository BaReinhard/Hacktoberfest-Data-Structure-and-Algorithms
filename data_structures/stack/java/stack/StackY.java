public class StackY 
{
    private double[] stackArray;
    private int maxSize;
    private int top;

    public StackY(int x){
        maxSize = x;
        stackArray = new double[maxSize];
        top = -1;
    }

    public void push(double i){
        if(top == (maxSize-1)){
            System.out.println("Stack full");
        }
        else{
            top = top + 1;
            stackArray[top] = i;
        }
    }

    public double pop(){
        if(top == -1){
            System.out.println("Stack Empty");
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
