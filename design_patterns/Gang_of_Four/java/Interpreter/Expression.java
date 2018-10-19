package Interpreter;

import java.util.Map;

public interface Expression {

    int interpret(Map<String, Expression> variables);
}
