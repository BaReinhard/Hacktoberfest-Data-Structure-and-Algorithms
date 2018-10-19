package Adapter;

import java.util.Random;

public class EnemyTank implements EnemyAttacker {
    // EnemyTank implements EnemyAttacker perfectly
    // Our job is to make classes with different methods
    // from EnemyAttacker to work with the EnemyAttacker interface

    private Random generator = new Random();

    @Override
    public void fireWeapon() {
        int attackDamage = generator.nextInt(10) + 1;
        System.out.println("Enemy Tank Does " + attackDamage + " Damage");
    }

    @Override
    public void driveForward() {
        int movement = generator.nextInt(10) + 1;
        System.out.println("Enemy Tank moves " + movement + " spaces forward");
    }

    @Override
    public void assignDriver(String driverName) {
        System.out.println(driverName + " is driving the tank");
    }
}
