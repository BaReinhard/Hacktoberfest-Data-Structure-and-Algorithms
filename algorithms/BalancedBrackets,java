import java.util.Scanner;
import java.util.Stack;

class BalancedBrackets {
    public static char findOpposite(char b) {
        switch(b) {
            case ')' : return '(';
            case '}' : return '{';
            case ']' : return '[';
        }
        return '*';
    }
    public static boolean CheckBalancedBrackets(String expression) {
        Stack<Character> brackets = new Stack<Character>();
        for (char c : expression.toCharArray()) {
            if (c == '(' || c == '{' || c == '[') {
                brackets.push(c);
            } 
            else if (c == ')' || c == '}' || c == ']') {
            	if (brackets.isEmpty()) {
            		return false;
            	}
                if (brackets.peek() == findOpposite(c)) {
                    brackets.pop();
                } else {
                    return false;
                }
            }
        }

        if (brackets.isEmpty()) {
            return true;
        }
        return false;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String exp = in.next();

        boolean isBalanced = CheckBalancedBrackets(exp);
        System.out.println(isBalanced);
    }
}
