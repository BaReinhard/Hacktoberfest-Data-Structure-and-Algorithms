package TemplateMethod;

public class ItalianHoagie extends Hoagie {

    private String[] meatUsed = {"Salami", "Pepperoni", "Capicola Ham"};
    private String[] cheeseUsed = {"Provolone"};
    private String[] veggiesUsed = {"Lettuce", "Tomatoes", "Onions", "Sweet Peppers"};
    private String[] condimentsUsed = {"Oil", "Vinegar"};

    @Override
    void addMeat() {
        System.out.print("Adding the meat: ");

        for (String meat : meatUsed)
            System.out.print(meat + " ");

        System.out.println();
    }

    @Override
    void addCheese() {
        System.out.print("Adding the cheese: ");

        for (String cheese : cheeseUsed)
            System.out.print(cheese + " ");

        System.out.println();
    }

    @Override
    void addVegetables() {
        System.out.print("Adding the vegetables: ");

        for (String vegetable : veggiesUsed)
            System.out.print(vegetable + " ");

        System.out.println();
    }

    @Override
    void addCondiments() {
        System.out.print("Adding the condiments: ");

        for (String condiment : condimentsUsed)
            System.out.print(condiment + " ");

        System.out.println();
    }
}
