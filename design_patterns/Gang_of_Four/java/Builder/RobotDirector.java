package Builder;

public class RobotDirector {

    private RobotBuilder robotBuilder;

    public RobotDirector(RobotBuilder robotBuilder) {
        this.robotBuilder = robotBuilder;
    }

    public Robot getRobot() {
        return robotBuilder.getRobot();
    }

    public void makeRobot() {
        robotBuilder.buildRobotHead();
        robotBuilder.buildRobotTorso();
        robotBuilder.buildRobotArms();
        robotBuilder.buildRobotLegs();
    }
}
