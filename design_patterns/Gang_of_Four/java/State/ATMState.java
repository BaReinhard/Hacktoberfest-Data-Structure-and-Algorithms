package State;

public interface ATMState {
    // Different states expected
    // HasCard, NoCard, HasPin, NoCash

    void insertCard();

    void ejectCard();

    void insertPin(int enteredPin);

    void requestCash(int cashToWithdraw);
}
