package Adapter;

public class Execute {

    public static void main(String[] args) {
        EnemyTank tank = new EnemyTank();
        EnemyRobot robot = new EnemyRobot();
        EnemyAttacker robotAdapter = new EnemyRobotAdapter(robot);

        System.out.println("ROBOT");

        robot.reactToHuman("Paul");
        robot.walkForward();
        robot.smashWithHands();
        System.out.println();

        System.out.println("TANK");

        tank.assignDriver("Frank");
        tank.driveForward();
        tank.fireWeapon();
        System.out.println();

        System.out.println("ROBOT WITH ADAPTER");

        robotAdapter.assignDriver("Mark");
        robotAdapter.driveForward();
        robotAdapter.fireWeapon();
    }
}
