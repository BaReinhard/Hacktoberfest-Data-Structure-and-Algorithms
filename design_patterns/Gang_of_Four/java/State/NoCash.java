package State;

public class NoCash implements ATMState {

    private ATMMachine atmMachine;

    public NoCash(ATMMachine atmMachine) {
        this.atmMachine = atmMachine;
    }

    @Override
    public void insertCard() {
        System.out.println("We don't have any money");
        System.out.println("Your card is ejected");
        atmMachine.setAtmState(atmMachine.getNoCardState());
    }

    @Override
    public void ejectCard() {
        System.out.println("We don't have any money");
    }

    @Override
    public void insertPin(int enteredPin) {
        System.out.println("We don't have any money");
    }

    @Override
    public void requestCash(int cashToWithdraw) {
        System.out.println("We don't have any money");
    }
}