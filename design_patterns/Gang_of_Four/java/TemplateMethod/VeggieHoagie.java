package TemplateMethod;

public class VeggieHoagie extends Hoagie {

    private String[] veggiesUsed = {"Lettuce", "Tomatoes", "Onions", "Sweet Peppers"};
    private String[] condimentsUsed = {"Oil", "Vinegar"};

    @Override
    boolean customerWantsMeat() {
        return false;
    }

    @Override
    boolean customerWantsCheese() {
        return false;
    }

    @Override
    void addMeat() {
    }

    @Override
    void addCheese() {
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
