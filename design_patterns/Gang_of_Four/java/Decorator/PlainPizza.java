package Decorator;

public class PlainPizza implements Pizza {

    PlainPizza() {
        System.out.println("Adding Dough");
    }

    @Override
    public String getDescription() {

        System.out.println();
        return "Thin Dough";
    }

    @Override
    public double getCost() {
        return 4.00;
    }
}
