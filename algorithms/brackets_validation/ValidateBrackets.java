import java.util.Stack;

/**
 * Validate if each open bracket has closing pair
 */
public class ValidateBrackets {
    public static void main(String[] args) {
        String notBalancedBrackets = "{}{{}}}";
        System.out.println(validate(notBalancedBrackets) ? "Balanced" : "Not balanced");

        String balancedBrackets = "{}";
        System.out.println(validate(balancedBrackets) ? "Balanced" : "Not balanced");

        String empty = "";
        System.out.println(validate(empty) ? "Balanced" : "Not balanced");
    }

    private static boolean validate(String brackets) {
        if (brackets.isEmpty()) return false;

        char[] bracketChars = brackets.toCharArray();

        Stack<Character> characterStack = new Stack<>();

        for (char current : bracketChars) {
            if (current == '{') {
                characterStack.push(current);
            } else {
                if (characterStack.isEmpty()) {
                    return false;
                }
                char last = characterStack.peek();
                if (current == '}' && last == '{') {
                    characterStack.pop();
                } else {
                    return false;
                }
            }
        }
        return characterStack.isEmpty();
    }
}