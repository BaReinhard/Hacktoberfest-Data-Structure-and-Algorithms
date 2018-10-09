import java.util.*;

class RPN {

    private static String operation(String t, int a, int b) {
        switch(t) {
            case "+":
                return Integer.toString(a + b);
            case "-":
                return Integer.toString(a - b);
            case "*":
                return Integer.toString(a * b);
            case "/":
                return Integer.toString(a / b);
            default:
                return "";
        }
    }

    public static String rpn(String inp) {
        StringTokenizer st = new StringTokenizer(inp);
        Deque<String> s = new LinkedList<>();
        String t;
        int a, b;
        while (st.hasMoreTokens()) {
            t = st.nextToken();
            if (t.matches("\\d+")) {
                s.push(t);
            }
            else {
                b = Integer.parseInt(s.pop());
                a = Integer.parseInt(s.pop());
                s.push(operation(t,a,b));
            }
        }
        return (s.pop());
    }
}