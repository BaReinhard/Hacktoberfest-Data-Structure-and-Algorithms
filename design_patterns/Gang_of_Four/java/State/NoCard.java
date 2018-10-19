package State;

public class NoCard implements ATMState {

    private ATMMachine atmMachine;

    public NoCard(ATMMachine atmMachine) {
        this.atmMachine = atmMachine;
    }

    @Override
    public void insertCard() {
        System.out.println("Card inserted. Please enter your pin");
        atmMachine.setAtmState(atmMachine.getHasCardState());
    }

    @Override
    public void ejectCard() {
        System.out.println("You didn't insert a card");
    }

    @Override
    public void insertPin(int enteredPin) {
        System.out.println("You didn't insert a card");
    }

    @Override
    public void requestCash(int cashToWithdraw) {
        System.out.println("You didn't insert a card");
    }
}