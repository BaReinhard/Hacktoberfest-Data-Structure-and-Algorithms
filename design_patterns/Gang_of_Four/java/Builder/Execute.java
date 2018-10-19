package Builder;

public class Execute {

    public static void main(String[] args) {
        RobotBuilder oldStyleRobot = new OldRobotBuilder();

        RobotDirector robotDirector = new RobotDirector(oldStyleRobot);
        robotDirector.makeRobot();

        Robot firstRobot = robotDirector.getRobot();

        System.out.println("Robot built");

        System.out.println("Robot Head type: " + firstRobot.getRobotHead());
        System.out.println("Robot Torso type: " + firstRobot.getRobotTorso());
        System.out.println("Robot Arm type: " + firstRobot.getRobotArms());
        System.out.println("Robot Leg type: " + firstRobot.getRobotLegs());
    }
}
