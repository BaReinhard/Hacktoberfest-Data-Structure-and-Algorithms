package Decorator;

public class Execute {

    public static void main(String[] args) {

        Pizza basicPizza = new TomatoSauce(new Mozzarella(new PlainPizza()));

        System.out.println("Ingredients: " + basicPizza.getDescription());
        System.out.println("Price: " + basicPizza.getCost());
    }
}
