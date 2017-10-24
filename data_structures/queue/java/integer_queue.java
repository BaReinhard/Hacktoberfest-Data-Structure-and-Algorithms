import java.util.ArrayList;
import java.util.List;

public class Queue {
    List<Integer> _data = new ArrayList<Integer>();
    int _top = -1;
    public Queue(){

    }
    public void Enqueue(int val){
        _top++;
        _data.add(val);
    }

    public void Dequeue(){
        if(!isEmpty())
            _data.remove(_top--);
        else
            System.out.println("Queue Is Empty");
    }

    public int Top(){
        return _data.get(_top);
    }
    private boolean isEmpty(){
        return _top == -1;
    }
}
