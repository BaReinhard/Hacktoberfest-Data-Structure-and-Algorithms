package Strategy;

public class Execute {

    public static void main(String[] args) {
        Dog dog = new Dog();
        Bird bird = new Bird();

        System.out.println("Dog : " + dog.tryToFly());
        System.out.println("Bird : " + bird.tryToFly());

        System.out.println("\nChanging flyingType of dog to ItFlys");
        dog.setFlyingType(new ItFlys());
        System.out.println("Dog : " + dog.tryToFly());

    }
}
