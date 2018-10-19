package State;

public class Execute {

    public static void main(String[] args) {

        // State Design Pattern allows an object to alter
        // its behaviour when its internal state changes.
        // The object will appear to change its class.

        ATMMachine atmMachine = new ATMMachine();
        atmMachine.insertCard();
        atmMachine.ejectCard();
        atmMachine.insertCard();
        atmMachine.insertPin(1234);
        atmMachine.requestCash(2000);
        atmMachine.insertCard();
        atmMachine.insertPin(1234);
    }
}
