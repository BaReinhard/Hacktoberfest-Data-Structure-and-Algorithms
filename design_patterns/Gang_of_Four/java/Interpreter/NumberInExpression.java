package Interpreter;

import java.util.Map;

public class NumberInExpression implements Expression {

    private int number;

    public NumberInExpression(int number) {
        this.number = number;
    }

    @Override
    public int interpret(Map<String, Expression> variables) {
        return number;
    }
}
