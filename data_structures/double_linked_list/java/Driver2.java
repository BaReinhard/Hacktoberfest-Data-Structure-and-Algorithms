public class Driver2
{
	public static void main(String[] args) {
		DoublyLinkedList ob1 = new DoublyLinkedList();
		ob1.insert_At_Head(5);
		ob1.insert_At_Head(15);
		ob1.insert_At_Head(25);
		ob1.insert_At_Tail(4);
		ob1.insert_At_Tail(2);
		DoubleNode n= new DoubleNode(15);
		ob1.insert_After_Node(n,28);
		ob1.print();
		ob1.reverse(ob1.head,2);
		//ob1.delete_Value(15);
		ob1.print();
	}
}