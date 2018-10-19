package Visitor;

interface Visitor {

    // The visitor pattern is used when you have to perform
    // the same action on many objects of different types

    // Created to automatically use the right code based on the
    // Object sent - Method Overloading

    public double visit(Liquor liquorItem);

    public double visit(Tobacco tobaccoItem);

    public double visit(Necessity necessityItem);

}
