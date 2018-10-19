package Strategy;

class Dog extends Animals {

    Dog() {
        super();

        flyingType = new CantFly();
    }
}
