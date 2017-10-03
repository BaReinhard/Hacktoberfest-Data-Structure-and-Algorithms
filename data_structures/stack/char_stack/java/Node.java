import java.util.*;

public class Node<T>{
  private T data;
  private Node nextNode;
  private Node previewNode;
  private int index;

  public Node(T data){
    this.data = data;
    this.nextNode = null;
    this.previewNode = null;
    this.index = 0;
  }

  public Node(){
    this.data = null;
    this.nextNode = null;
    this.previewNode = null;
    this.index = 0;
  }

  public T getData(){
    return this.data;
  }

  public void setData(T data){
    this.data = data;
  }

  public int getIndex(){
    return this.index;
  }

  public void setNext(Node node){
    this.nextNode = node;
  }

  public Node getNext(){
      return this.nextNode;
  }

  public void setPreview(Node node){
    this.previewNode = node;
  }

  public Node getPreview(){
      return this.previewNode;
  }
}
