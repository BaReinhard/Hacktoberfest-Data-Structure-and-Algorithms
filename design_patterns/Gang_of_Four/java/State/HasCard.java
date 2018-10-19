package State;

public class HasCard implements ATMState {

    private ATMMachine atmMachine;

    public HasCard(ATMMachine atmMachine) {
        this.atmMachine = atmMachine;
    }

    @Override
    public void insertCard() {
        System.out.println("You can only insert one card at a time");
    }

    @Override
    public void ejectCard() {
        System.out.println("Your card is ejected");
        atmMachine.setAtmState(atmMachine.getNoCardState());
    }

    @Override
    public void insertPin(int enteredPin) {

        if (enteredPin == 1234) {
            System.out.println("You entered the correct PIN");
            atmMachine.correctPinEntered = true;
            atmMachine.setAtmState(atmMachine.getHasPinState());
        } else {
            System.out.println("You entered the WRONG PIN");
            atmMachine.correctPinEntered = false;
            System.out.println("Your card is ejected");
            atmMachine.setAtmState(atmMachine.getNoCardState());
        }
    }

    @Override
    public void requestCash(int cashToWithdraw) {
        System.out.println("You have not entered your PIN");
    }
}
