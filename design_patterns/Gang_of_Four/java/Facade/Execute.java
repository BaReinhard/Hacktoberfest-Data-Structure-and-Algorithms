package Facade;

public class Execute {

    public static void main(String[] args) {
        BankAccountFacade accessingBank = new BankAccountFacade(123456789, 9999);
        accessingBank.withdrawCash(50);
        accessingBank.withdrawCash(900);
        accessingBank.withdrawCash(1200);
        accessingBank.depositCash(2000);
        accessingBank.withdrawCash(1200);
    }
}
