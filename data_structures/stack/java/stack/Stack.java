public class Stack
{
    public static void main(String ar[])
    {
        StackY stacky = new StackY(10);
        stacky.push(10);
        stacky.push(50);
        stacky.push(12);
        stacky.push(70);

        while(!stacky.isEmpty())
        {
            System.out.println(stacky.pop());
            System.out.println("");
        }
    }
}