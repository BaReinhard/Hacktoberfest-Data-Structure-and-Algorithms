package Interpreter;

import java.util.Map;
import java.util.Stack;

public class Evaluator implements Expression {

    // While the interpreter pattern does not address
    // parsing, a parser is provided for completeness.

    private Expression syntaxTree;

    public Evaluator(String expression) {
        final Stack<Expression> expressionStack = new Stack<>();

        for (String token : expression.split(" ")) {
            if (token.equals("+")) {
                Expression subExpression = new Plus(expressionStack.pop(), expressionStack.pop());
                expressionStack.push(subExpression);
            } else if (token.equals("-")) {
                Expression subExpression = new Minus(expressionStack.pop(), expressionStack.pop());
                expressionStack.push(subExpression);
            } else {
                Expression subExpression = new Variable(token);
                expressionStack.push(subExpression);
            }
        }

        syntaxTree = expressionStack.pop();
    }

    @Override
    public int interpret(Map<String, Expression> variables) {
        return syntaxTree.interpret(variables);
    }

}
