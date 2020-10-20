public class StackCharApp 
{
    public static void main(String ar[])
    {
        StackCharY stackchary = new StackCharY(5);
        stackchary.push('A');
        stackchary.push('B');
        stackchary.push('C');
        stackchary.push('D');

        while(!stackchary.isEmpty())
        {
            char x = stackchary.pop();
            System.out.println(x);
            System.out.println();
        }
    }
}
