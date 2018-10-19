package Factory;

import java.util.Scanner;

public class Execute {

    public static void main(String[] args) {

        EnemyShipFactory shipFactory = new EnemyShipFactory();
        EnemyShip enemy;

        Scanner sc = new Scanner(System.in);
        System.out.println("What type of ship? (U / R)");
        String typeOfShip = sc.next();

        enemy = shipFactory.makeEnemyShip(typeOfShip);

        if (enemy != null)
            doStuffEnemy(enemy);
        else
            System.out.println("Enter U or R next time");
    }

    private static void doStuffEnemy(EnemyShip enemyShip) {
        enemyShip.displayEnemyShip();
        enemyShip.followHeroShip();
        enemyShip.enemyShipShoots();
    }
}
