package ChainOfResponsibility;

public interface Chain {
    // The chain of responsibility pattern has a
    // group of objects that are expected to between
    // them be able to solve a problem.
    // If the first Object can't solve it, it passes
    // the data to the next Object in the chain

    int THOUSAND = 1000;
    int HUNDRED = 100;
    int TEN = 10;
    int ONE = 1;

    // Defines the next Object to receive the data
    // if this Object can't process it

    void setNextInChain(Chain nextInChain);

    // Either solves the problem or passes the data
    // to the next Object in the chain

    void calculateDenominations(int amount);
}
