using System; 
using System.Collections.Generic;
namespace Stack{
        public class main{
            static void Main(){
                Stack<int> stack = new Stack<int>();
                stack.Push(1);
                stack.Push(3);
                Console.WriteLine(stack.Top());
                stack.Pop();
                Console.WriteLine(stack.Top());
                
            }
        }
}