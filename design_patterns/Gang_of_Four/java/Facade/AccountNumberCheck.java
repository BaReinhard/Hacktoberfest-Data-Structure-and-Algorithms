package Facade;

public class AccountNumberCheck {

    private int accNo = 123456789;

    public int getAccNo() {
        return accNo;
    }

    public boolean isAccountActive(int accNumToCheck) {
        return accNumToCheck == getAccNo();
    }

}
