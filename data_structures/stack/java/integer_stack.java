import java.util.ArrayList;
import java.util.List;

public class Stack {
    private List<Integer> _data = new ArrayList<Integer>();
    private int _top = -1;
    public Stack(){

    }
    public void Push(int val){
        _top++;
        _data.add(val);
    }

    public void Pop(){
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

