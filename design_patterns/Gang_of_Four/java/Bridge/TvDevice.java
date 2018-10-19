package Bridge;

public class TvDevice extends EntertainmentDevice {

    // Concrete Implementor

    // Here is an implementation of the EntertainmentDevice
    // abstract class. I'm specifying what makes it different
    // from other devices

    public TvDevice(int deviceState, int maxState) {
        super(deviceState, maxState);
    }

    @Override
    public void buttonFivePressed() {
        System.out.println("Channel Down");
        deviceState--;
    }

    @Override
    public void buttonSixPressed() {
        System.out.println("Channel Up");
        deviceState++;
    }
}
