public class DoublyLinkedList
{
	public DoubleNode head=null;
	public void insert_At_Head(int x)
	{
		DoubleNode newnode= new DoubleNode(x);
		if(head==null)
		{
			head=newnode;
		}
		else
		{
			head.prev=newnode;
			newnode.next=head;
			head=newnode;
		}
	}
	public void insert_At_Tail(int x)
	{
		DoubleNode newnode = new DoubleNode(x);
		if(head==null)
			head=newnode;
		else
		{
			DoubleNode temp=head;
			while(temp.next!=null)
				temp=temp.next;
			temp.next=newnode;
			newnode.prev=temp.next;
		}
	}
	public void delete_Value(int value)
	{
		DoubleNode temp=head;
		while(temp.data!=value)
		{
			temp=temp.next;
		}
		temp.prev.next=temp.next;
		temp.next.prev=temp.prev;
	}
	public void insert_At_Position(int value,int k)
	{
		DoubleNode temp=head;
		DoubleNode newnode = new DoubleNode(value);
		int count=1;
		if(k==1)
		{
			newnode.next=head;
			head=newnode;
		}
		else
		{
			while(count!=k-1)
			{
				temp=temp.next;
				count++;
			}
			if(temp.next==null)
			{
				newnode.prev=temp;
				temp.next=newnode;
			}
			else
			{
				newnode.next=temp.next;
				newnode.prev=temp;
				temp.next.prev=newnode;
				temp.next=newnode;
			}
		}
	}
	public void insert_After_Node(DoubleNode n,int x)
	{
		DoubleNode temp=head;
		DoubleNode newnode = new DoubleNode(x);
		while(temp.data!=n.data)
		{
			temp=temp.next;
		}
		newnode.next=temp.next;
		temp.next.prev=newnode;
		newnode.prev=temp;
		temp.next=newnode;
	}	
	public void print()
	{
		DoubleNode temp=head;
		while(temp.next!=null)
		{
			System.out.print(temp.data+" ");
			temp=temp.next;
		}
		System.out.print(temp.data+" ");
		System.out.println();
	}
	public DoubleNode reverse(DoubleNode head,int k)
	{
		/*DoubleNode temp = null;
        DoubleNode current = head;
        DoubleNode next = null;
        while (current != null) {
            temp = current.prev;
            current.prev = current.next;
            current.next = temp;
            current=current.prev;
        }
        head=current;*/
       DoubleNode current = head;
       DoubleNode next = null;
       DoubleNode prev = null;
       int count = 0;
      /* Reverse first k nodes of linked list */
       while (count < k ) 
       {
           next = current.next;
           current.next = prev;
           prev = current;
           current = next;
           count++;
       }

       /* next is now a pointer to (k+1)th node 
          Recursively call for the list starting from current.
          And make rest of the list as next of first node */
       if (next != null) 
          head.next = reverse(next, k);

       // prev is now head of input list
       return prev;
	}
}