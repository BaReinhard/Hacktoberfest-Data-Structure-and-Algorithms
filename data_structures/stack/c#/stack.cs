using System; 
using System.Collections.Generic;
 
namespace Stack{
   public class Stack<t>  {
        private List<t> _array;     // Storage for stack elements  
        private int _top;    // Number of items in the stack.
        static List<t> _emptyArray = new List<t>(); 
    
       public int Size { get { return _array.Count; } }
    
        public Stack(){
            
            _array = _emptyArray;
            _top = -1;
            
        }
        public void Push(t data){
            _array.Add(data);
            _top++;
        }
        public void Pop(){
            if(_top != -1 )
                _array.RemoveAt(_top--);
            else
                Console.WriteLine("There is no element on your stack.");
        }
        public t Top(){
            if(_top != -1 ){
                return _array[_top];
            }else{
                Console.WriteLine("There is no element on your stack.");
                return default(t);
            }
        }
    }
}

      
