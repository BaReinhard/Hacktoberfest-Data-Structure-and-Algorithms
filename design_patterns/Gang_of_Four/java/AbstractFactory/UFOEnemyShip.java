package AbstractFactory;

public class UFOEnemyShip extends EnemyShip{

    // We define the type of ship we want to create
    // by stating we want to use the factory that
    // makes enemy ships

    EnemyShipFactory shipFactory;

    // The enemy ship required parts list is sent to
    // this method. They state that the enemy ship
    // must have a weapon and engine assigned. That
    // object also states the specific parts needed
    // to make a regular UFO versus a Boss UFO

    public UFOEnemyShip(EnemyShipFactory shipFactory){

        this.shipFactory = shipFactory;

    }

    // EnemyShipBuilding calls this method to build a
    // specific UFOEnemyShip

    void makeShip() {

        System.out.println("Making enemy ship " + getName());

        // The specific weapon & engine needed were passed in
        // shipFactory. We are assigning those specific part
        // objects to the UFOEnemyShip here

        weapon = shipFactory.addESGun();
        engine = shipFactory.addESEngine();

    }

}