package Facade;

public class FundsCheck {

    private double balance = 1000.00;

    public double getBalance() {
        return balance;
    }

    public void decreaseBalance(double cashWithdrawn) {
        balance -= cashWithdrawn;
    }

    public void increaseBalance(double cashDeopsited) {
        balance += cashDeopsited;
    }

    public boolean haveEnoughBalance(double cashToWithdraw) {
        if (cashToWithdraw > getBalance()) {
            System.out.println("Error : You don't have enough balance");
            System.out.println("Current Balance: " + getBalance());
            return false;

        } else {
            decreaseBalance(cashToWithdraw);
            System.out.println("Withdrawal completed!");
            System.out.println("Current Balance: " + getBalance());
            return true;
        }
    }

    public void makeDeposit(double cashToDeposit) {
        increaseBalance(cashToDeposit);
        System.out.println("Deposit completed!");
        System.out.println("Current Balance: " + getBalance());
    }
}
