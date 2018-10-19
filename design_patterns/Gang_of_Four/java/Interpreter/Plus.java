package Interpreter;

import java.util.Map;

public class Plus implements Expression {

    private Expression rightOperand;
    private Expression leftOperand;

    public Plus(Expression rightOperand, Expression leftOperand) {
        this.rightOperand = rightOperand;
        this.leftOperand = leftOperand;
    }

    @Override
    public int interpret(Map<String, Expression> variables) {
        return leftOperand.interpret(variables) + rightOperand.interpret(variables);
    }
}
