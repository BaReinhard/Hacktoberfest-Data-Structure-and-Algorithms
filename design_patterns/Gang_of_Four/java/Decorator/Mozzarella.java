package Decorator;

public class Mozzarella extends ToppingDecorator {

    public Mozzarella(Pizza pizza) {
        super(pizza);

        System.out.println("Adding Moz");
    }

    public String getDescription() {
        return tempPizza.getDescription() + " , Mozarella";
    }

    public double getCost() {
        return tempPizza.getCost() + .50;
    }
}
