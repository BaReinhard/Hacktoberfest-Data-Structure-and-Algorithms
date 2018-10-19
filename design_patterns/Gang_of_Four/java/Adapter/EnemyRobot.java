package Adapter;

import java.util.Random;

public class EnemyRobot {
    // This is the Adaptee. The Adapter sends method calls
    // to objects that use the EnemyAttacker interface
    // to the right methods defined in EnemyRobot

    private Random generator = new Random();

    void smashWithHands() {
        int attackDamage = generator.nextInt(10) + 1;
        System.out.println("Enemy Robot causes " + attackDamage + " damage with its hands");
    }

    void walkForward() {
        int movement = generator.nextInt(10) + 1;
        System.out.println("Enemy Robot walks forward " + movement + " spaces");
    }

    void reactToHuman(String driverName) {
        System.out.println("Enemy Robot tramps on " + driverName);
    }
}