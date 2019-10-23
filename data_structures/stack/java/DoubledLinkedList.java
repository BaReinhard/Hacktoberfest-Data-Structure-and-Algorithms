import java.util.*;

public class DoubledLinkedList<T>{
  private T data;
  private Node nextNode;
  private Node previewNode;
  private int index;

  public DoubledLinkedList(T data){
    this.data = data;
    this.nextNode = null;
    this.previewNode = null;
    this.index = 0;
  }

  public DoubledLinkedList(){
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
