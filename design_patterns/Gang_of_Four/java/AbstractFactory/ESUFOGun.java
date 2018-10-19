package AbstractFactory;

// Here we define a basic component of a space ship
// Any part that implements the interface ESWeapon
// can replace that part in any ship

public class ESUFOGun implements ESWeapon{

    // EnemyShip contains a reference to the object
    // ESWeapon. It is stored in the field weapon

    // The Strategy design pattern is being used here

    // When the field that is of type ESUFOGun is printed
    // the following shows on the screen

    public String toString(){
        return "20 damage";
    }

}