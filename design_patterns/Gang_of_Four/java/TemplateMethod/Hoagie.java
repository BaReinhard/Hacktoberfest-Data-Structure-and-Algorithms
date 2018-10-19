package TemplateMethod;

abstract class Hoagie {
    // A Template Method Pattern contains a method that provides
    // the steps of the algorithm. It allows subclasses to override
    // some of the methods as per need but the invocation is to be
    // in the same way as defined.

    final void makeSandwich() {

        cutBun();

        if (customerWantsMeat())
            addMeat();

        if (customerWantsCheese())
            addCheese();

        if (customerWantsVegetables())
            addVegetables();

        if (customerWantsCondiments())
            addCondiments();

        wrapTheHoagie();
    }

    public void cutBun() {
        System.out.println("The Hoagie is Cut");
    }

    public void wrapTheHoagie() {
        System.out.println("Wrap the Hoagie");
    }

    // These methods must be overridden by the extending subclasses

    abstract void addMeat();

    abstract void addCheese();

    abstract void addVegetables();

    abstract void addCondiments();

    // These are called hooks
    // If the user wants to override these they can
    // Use abstract methods when you want to force the user
    // to override and use a hook when you want it to be optional

    boolean customerWantsMeat() {
        return true;
    }

    boolean customerWantsCheese() {
        return true;
    }

    boolean customerWantsVegetables() {
        return true;
    }

    boolean customerWantsCondiments() {
        return true;
    }
}

