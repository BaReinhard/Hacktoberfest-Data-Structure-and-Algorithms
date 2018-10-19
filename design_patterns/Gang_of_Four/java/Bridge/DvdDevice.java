package Bridge;

public class DvdDevice extends EntertainmentDevice {

    // Concrete Implementor

    // Here is an implementation of the EntertainmentDevice
    // abstract class. I'm specifying what makes it different
    // from other devices

    public DvdDevice(int deviceState, int maxState) {
        super(deviceState, maxState);
    }

    @Override
    public void buttonFivePressed() {
        System.out.println("DVD Skips to previous chapter");
        deviceState--;
    }

    @Override
    public void buttonSixPressed() {
        System.out.println("DVD Skips to next chapter");
        deviceState++;
    }
}
