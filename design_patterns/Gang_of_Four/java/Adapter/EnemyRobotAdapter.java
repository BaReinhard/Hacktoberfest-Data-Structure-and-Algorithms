package Adapter;

public class EnemyRobotAdapter implements EnemyAttacker {
    // The Adapter must provide an alternative action for
    // the the methods that need to be used because
    // EnemyAttacker was implemented.

    // This adapter does this by containing an object
    // of the same type as the Adaptee (EnemyRobot)
    // All calls to EnemyAttacker methods are sent
    // instead to methods used by EnemyRobot

    private EnemyRobot enemyRobot;

    public EnemyRobotAdapter(EnemyRobot enemyRobot) {
        this.enemyRobot = enemyRobot;
    }

    @Override
    public void fireWeapon() {
        enemyRobot.smashWithHands();
    }

    @Override
    public void driveForward() {
        enemyRobot.walkForward();
    }

    @Override
    public void assignDriver(String driverName) {
        enemyRobot.reactToHuman(driverName);
    }
}
