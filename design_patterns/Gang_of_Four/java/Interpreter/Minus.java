package Interpreter;

import java.util.Map;

public class Minus implements Expression {

    private Expression rightOperand;
    private Expression leftOperand;

    public Minus(Expression rightOperand, Expression leftOperand) {
        this.rightOperand = rightOperand;
        this.leftOperand = leftOperand;
    }

    @Override
    public int interpret(Map<String, Expression> variables) {
        return rightOperand.interpret(variables) - leftOperand.interpret(variables);
    }
}
