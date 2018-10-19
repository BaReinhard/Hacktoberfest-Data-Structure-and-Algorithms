package Facade;

public class SecurityCodeCheck {

    private int securityCode = 9999;

    public int getSecurityCode() {
        return securityCode;
    }

    public boolean isCodeCorrect(int secCodeToCheck) {
        return secCodeToCheck == getSecurityCode();
    }
}
