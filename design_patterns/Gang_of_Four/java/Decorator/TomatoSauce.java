package Decorator;

public class TomatoSauce extends ToppingDecorator {

    public TomatoSauce(Pizza pizza) {
        super(pizza);

        System.out.println("Adding Sauce");
    }

    public String getDescription() {
        return tempPizza.getDescription() + " , Tomato Sauce";
    }

    public double getCost() {
        return tempPizza.getCost() + .35;
    }
}
