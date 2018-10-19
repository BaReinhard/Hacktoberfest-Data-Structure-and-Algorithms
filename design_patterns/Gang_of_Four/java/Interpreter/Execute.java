package Interpreter;

import java.util.HashMap;
import java.util.Map;

public class Execute {

    // Finally evaluating the expression
    // "w x z - +" with w = 5, x = 10, and z = 42.

    public static void main(String[] args) {

        String expression = "w x z - +";

        Evaluator evaluator = new Evaluator(expression);

        Map<String, Expression> variables = new HashMap<>();
        variables.put("w", new NumberInExpression(5));
        variables.put("x", new NumberInExpression(10));
        variables.put("z", new NumberInExpression(42));

        int result = evaluator.interpret(variables);

        System.out.println("Given: w = 5, x = 10, and z = 42");
        System.out.println("Result of wxz-+ is: " + result);
    }
}
