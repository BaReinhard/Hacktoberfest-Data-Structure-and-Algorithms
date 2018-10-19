package Builder;

public class OldRobotBuilder implements RobotBuilder {

    private Robot robot;

    public OldRobotBuilder() {
        robot = new Robot();
    }

    @Override
    public void buildRobotHead() {
        robot.setRobotHead("Tin Head");
    }

    @Override
    public void buildRobotTorso() {
        robot.setRobotTorso("Tin Torso");
    }

    @Override
    public void buildRobotArms() {
        robot.setRobotArms("Blowtorch Arms");
    }

    @Override
    public void buildRobotLegs() {
        robot.setRobotLegs("Roller skates legs");
    }

    @Override
    public Robot getRobot() {
        return robot;
    }
}
