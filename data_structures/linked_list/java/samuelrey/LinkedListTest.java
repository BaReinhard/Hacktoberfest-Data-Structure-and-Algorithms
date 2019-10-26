import java.lang.IndexOutOfBoundsException;

public class LinkedListTest {
    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<>();
        list.insert(4);
        int x = list.get(0);
        assert(x == 4);
        list.remove(0);
        try {
            list.get(0);
            assert(false);
        } catch(IndexOutOfBoundsException e) {
            // pass
        }
    }
}
