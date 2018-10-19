package Factory;

public class EnemyShipFactory {

    public EnemyShip makeEnemyShip(String newShipType) {

        switch (newShipType) {
            case "U":
                return new UFOEnemyShip();
            case "R":
                return new RocketEnemyShip();
            default:
                return null;
        }

    }
}
