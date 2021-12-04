import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Stack;

class Bracket {
    Bracket(char type, int position) {
        this.type = type;
        this.position = position;
    }

    boolean Match(char c) {
        if (this.type == '[' && c == ']')
            return true;
        if (this.type == '{' && c == '}')
            return true;
        if (this.type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
}

class check_brackets {
    public static void main(String[] args) throws IOException {
        InputStreamReader input_stream = new InputStreamReader(System.in);
        BufferedReader reader = new BufferedReader(input_stream);
        String text = reader.readLine();

        Stack<Bracket> opening_brackets_stack = new Stack<Bracket>();
        for (int position = 0; position < text.length(); ++position) {
            char next = text.charAt(position);

            if (next == '(' || next == '[' || next == '{') {
                // Process opening bracket, write your code here

                //Adding the stack at the top of it, and pusing the old at bottom
                //Like LIFO
                opening_brackets_stack.push(new Bracket(next, position));

            }

            if (next == ')' || next == ']' || next == '}') {
                // Process closing bracket, write your code here

                //Check for the stack if it is empty, if it is then, it will increment the position
                if(opening_brackets_stack.isEmpty()){
                    System.out.println(position + 1);
                    return;
                }
                //Remove the object as top of the stack
                //If not matches then it will increment the position
                Bracket top = opening_brackets_stack.pop();
                if(!top.Match(next)){
                    System.out.println(position + 1);
                    return;
                }
            }
        }

        // Printing answer, write your code here
        System.out.println(opening_brackets_stack.isEmpty() ? "Success" : opening_brackets_stack.peek().position + 1);
    }
}
