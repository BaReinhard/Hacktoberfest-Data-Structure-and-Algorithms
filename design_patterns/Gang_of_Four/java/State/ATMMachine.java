package State;

public class ATMMachine {

    // Context class
    // Maintains an instance of a ConcreteState that
    // defines the current state

    private ATMState hasCard;
    private ATMState noCard;
    private ATMState hasCorrectPin;
    private ATMState noCash;

    private ATMState atmState;

    public int cashInMachine = 2000;
    public boolean correctPinEntered = false;

    public ATMMachine() {
        hasCard = new HasCard(this);
        noCard = new NoCard(this);
        hasCorrectPin = new HasPin(this);
        noCash = new NoCash(this);

        atmState = noCard;

        if (cashInMachine < 0)
            atmState = noCash;
    }

    public void setAtmState(ATMState atmState) {
        this.atmState = atmState;
    }

    public void setCashInMachine(int cashInMachine) {
        this.cashInMachine = cashInMachine;
    }

    public void insertCard() {
        atmState.insertCard();
    }

    public void ejectCard() {
        atmState.ejectCard();
    }

    public void insertPin(int enteredPin) {
        atmState.insertPin(enteredPin);
    }

    public void requestCash(int cashToWithdraw) {
        atmState.requestCash(cashToWithdraw);
    }

    // Getters for different States

    public ATMState getHasCardState() {
        return hasCard;
    }

    public ATMState getNoCardState() {
        return noCard;
    }

    public ATMState getHasPinState() {
        return hasCorrectPin;
    }

    public ATMState getNoCashState() {
        return noCash;
    }
}
