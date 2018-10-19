package Adapter;

public interface EnemyAttacker {
    // This is the Target Interface : This is what the client
    // expects to work with. It is the adapters job to make new
    // classes compatible with this one.

    void fireWeapon();

    void driveForward();

    void assignDriver(String driverName);
}
