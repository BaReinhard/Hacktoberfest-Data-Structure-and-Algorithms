using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructures
{
    /*
     * Implementing methods from https://www.cs.cmu.edu/~adamchik/15-121/lectures/Linked%20Lists/linked%20lists.html
     */

    class LinkedList
    {

        LinkedListNode head = null;


        public class LinkedListNode
        {
            object data;
            LinkedListNode next = null;

            public LinkedListNode(object newitem)
            {
                data = newitem;
            }

            public LinkedListNode(object newitem, LinkedListNode next)
            {
                data = newitem;
                this.next = next;
            }

            public object getData()
            {
                return data;
            }

            public LinkedListNode getNextNode()
            {
                return next;
            }

            public void setNextNode(LinkedListNode next)
            {
                this.next = next;
            }

        }


        public LinkedList(object data)
        {
            head = new LinkedListNode(data);
        }


        public void addFirst(object data)
        {
            head = new LinkedListNode(data, head);
        }


        public void addLast(object data)
        {
            if (head == null)
            {
                addFirst(data);
            }
            else
            {
                LinkedListNode temp = head;
                while (temp.getNextNode() != null)
                {
                    temp = temp.getNextNode();
                }
                temp.setNextNode(new LinkedListNode(data));
            }
        }


        public void insertAfter(object data, object newData)
        {
            LinkedListNode temp = head;
            while ((temp != null) && (temp.getData() != data))
            {
                temp = temp.getNextNode();
            }

            if (temp != null)
            { 
                temp.setNextNode(new LinkedListNode(newData, temp));
            }
        }


        public void insertBefore(object data, object newData)
        {
            if (head == null)
            {
                return;
            }
            if (head.getData() == data)
            {
                addFirst(newData);
                return;
            }

            LinkedListNode prev = null;
            LinkedListNode curr = head;

            while ((curr != null) && (curr.getData() != data))
            {
                prev = curr;
                curr = curr.getNextNode();
            }

            if (curr != null)
            {
                prev.setNextNode(new LinkedListNode(newData, curr));
            }
        }


        public void remove(object data)
        {
            if (head == null)
            {
                throw new Exception("List is empty, cannot delete.");
            }

            if (head.getData() == data)
            {
                head = head.getNextNode();
                return;
            }

            LinkedListNode prev = null;
            LinkedListNode curr = head;

            while ((curr != null) && (curr.getData() != data))
            {
                prev = curr;
                curr = curr.getNextNode();
            }

            if (curr == null)
            {
                throw new Exception("Cannot delete.");
            }

            prev.setNextNode(curr.getNextNode());
        }


    }
}
