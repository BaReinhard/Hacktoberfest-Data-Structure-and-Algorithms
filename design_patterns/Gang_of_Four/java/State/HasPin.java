package State;

public class HasPin implements ATMState {

    private ATMMachine atmMachine;

    public HasPin(ATMMachine atmMachine) {
        this.atmMachine = atmMachine;
    }

    @Override
    public void insertCard() {
        System.out.println("You already inserted a card");
    }

    @Override
    public void ejectCard() {
        System.out.println("You already entered a card");
        atmMachine.setAtmState(atmMachine.getNoCardState());
    }

    @Override
    public void insertPin(int enteredPin) {
        System.out.println("You already entered a PIN");
    }

    @Override
    public void requestCash(int cashToWithdraw) {

        if (cashToWithdraw > atmMachine.cashInMachine) {
            System.out.println("You don't have that much cash available");
            System.out.println("Your card is ejected");
            atmMachine.setAtmState(atmMachine.getNoCardState());

        } else {
            System.out.println("Amount " + cashToWithdraw + " withdrawn");
            int balance = atmMachine.cashInMachine - cashToWithdraw;
            atmMachine.setCashInMachine(balance);
            System.out.println("Balance: " + balance);

            System.out.println("Your card is ejected");
            atmMachine.setAtmState(atmMachine.getNoCardState());

            if (balance <= 0)
                atmMachine.setAtmState(atmMachine.getNoCashState());
        }
    }
}