import java.util.*;

public class Stack<T>{
  private Node topNode;
  private int size;

  public Stack(){
    this.topNode = null;
    this.size = 0;
  }

  public boolean isEmpty(){
    return this.size == 0;
  }

  public void push(T data){
    Node node = new Node<T>();
    node.setData(data);
    if(!isEmpty()){
      node.setPreview(this.topNode);
      this.topNode.setNext(node);
      this.topNode = node;
    }else{
      this.topNode = node;
    }
    this.size++;
  }

  public T top(){
    if(!isEmpty()){
      return (T) this.topNode;
    }
    return null;
  }

  public void pop(){
    if(!isEmpty()){
      if(this.size == 1){
        this.topNode = null;
      }else{
        Node a = this.topNode.getPreview();
        a.setNext(null);
        this.topNode = a;
      }
      this.size--;
    }else{
      System.out.println("There is no object on the stack!");
    }
  }

  public void viewStack(){
    if(!isEmpty()){
      Node node = this.topNode;
      while(node != null){
        System.out.println(node.getData());
        node = node.getPreview();
      }
    }else{
      System.out.println("Stack is Empty!");
    }
  }

    public static void main(String[] args) {
      Stack s = new Stack<>();
      s.push("a");
      s.push("aa");
      s.push("aaa");
      s.push("aaaa");

      s.viewStack();
      System.out.println("-------------------------");
      s.pop();
      s.viewStack();
      System.out.println("-------------------------");
      s.pop();
      s.viewStack();
      System.out.println("-------------------------");
      s.pop();
      s.viewStack();
      System.out.println("-------------------------");
      s.pop();
      s.viewStack();
      System.out.println("-------------------------");
    }

}
