using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructures
{
    class Stack
    {
        private List<Object> items = new List<Object>();

        public Object pop()
        {
            if (items.Count > 0)
            {
                int lastPos = items.Count - 1;
                Object temp = items[lastPos];
                items.RemoveAt(lastPos);
                return temp;
            }
            else
            {
                throw new Exception("Underflow: Stack is empty");
            }
        }

        public void push(Object newItem)
        {
            items.Add(newItem);
        }


        public bool isEmpty()
        {
            return (items.Count == 0);
        }

    }
}
