import java.util.*;

class ShtYard {

    private static int priority(String check) {
        switch(check) {
            case "(":
                return 0;
            case "+":
            case "-":
                return 1;
            default:
                return 2;
        }
    }

    public static String in2post(String inp) {
        StringTokenizer st = new StringTokenizer(inp);
        Deque<String> s = new LinkedList<>();
        Queue<String> q = new LinkedList<>();

        String t,res = "";
        
        while (st.hasMoreTokens()) {
            t = st.nextToken();
            if (t.matches("\\d+")) q.add(t);
            else if (t.equals("(")) s.push(t);
            else if (t.equals(")")) {
                while (!s.peek().equals("(")) q.add(s.pop());
                s.pop();
            } else {
                while (!s.isEmpty() && (priority(s.peek()) >= priority(t))) q.add(s.pop());
            }
            s.push(t);
        }
        while (!s.isEmpty()) q.add(s.pop());
        while (!q.isEmpty()) res += q.pop() + " ";
        
        return res; 
    }
}