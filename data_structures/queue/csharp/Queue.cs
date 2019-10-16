using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructures
{
    class Queue
    {

        private List<Object> queue = new List<Object>();

        public Object dequeue()
        {
            if (queue.Count > 0)
            {
                Object temp = queue[0];
                queue.RemoveAt(0);
                return temp;
            }
            else
            {
                return null;
            }
        }


        public Object peek()
        {
            if (queue.Count > 0)
            {
                return queue[0];
            }
            else
            {
                return null;
            }
        }


        public void enqueue(Object newItem)
        {
            queue.Add(newItem);
        }

        
        public bool isEmpty()
        {
            return (queue.Count == 0);
        }


    }
}
