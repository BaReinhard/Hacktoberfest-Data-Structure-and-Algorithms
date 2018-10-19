package Interpreter;

import java.util.Map;

public class Variable implements Expression {

    private String name;

    public Variable(String name) {
        this.name = name;
    }

    @Override
    public int interpret(Map<String, Expression> variables) {
        if (variables.get(name) == null)
            return 0;
        else
            return variables.get(name).interpret(variables);
    }
}
