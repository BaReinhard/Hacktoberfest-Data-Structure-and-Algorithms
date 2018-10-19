package Facade;

public class BankAccountFacade {

    private int accountNo;
    private int securityCode;

    private AccountNumberCheck accountNumberCheck;
    private SecurityCodeCheck securityCodeCheck;
    private FundsCheck fundsCheck;

    public BankAccountFacade(int accountNo, int securityCode) {
        this.accountNo = accountNo;
        this.securityCode = securityCode;

        new WelcomeToBank();
        accountNumberCheck = new AccountNumberCheck();
        securityCodeCheck = new SecurityCodeCheck();
        fundsCheck = new FundsCheck();
    }

    public int getAccountNo() {
        return accountNo;
    }

    public int getSecurityCode() {
        return securityCode;
    }

    public void withdrawCash(double cashToWithdraw) {
        if (accountNumberCheck.isAccountActive(accountNo)
                && securityCodeCheck.isCodeCorrect(securityCode)
                && fundsCheck.haveEnoughBalance(cashToWithdraw))
            System.out.println("TRANSACTION COMPLETED!\n");

        else
            System.out.println("TRANSACTION FAILED\n");
    }

    public void depositCash(double cashToDeposit) {
        fundsCheck.makeDeposit(cashToDeposit);
        System.out.println("TRANSACTION COMPLETED!\n");
    }
}
