package Bridge;

abstract class EntertainmentDevice {
    // Implementor
    // With the Bridge Design Pattern you create 2 layers of abstraction
    // In this example I'll have an abstract class representing
    // different types of devices. I also have an abstract class
    // that will represent different types of remote controls

    // This allows me to use an infinite variety of devices and remotes

    public int deviceState;
    public int maxState;
    public int volumeLevel = 0;

    public EntertainmentDevice(int deviceState, int maxState) {
        this.deviceState = deviceState;
        this.maxState = maxState;
    }

    public abstract void buttonFivePressed();

    public abstract void buttonSixPressed();

    public void deviceFeedback() {
        if (deviceState > maxState || deviceState < 0)
            deviceState = 0;

        System.out.println("On Channel: " + deviceState);
    }

    public void buttonSevenPressed() {
        volumeLevel++;
        System.out.println("Volume at: " + volumeLevel);
    }

    public void buttonEightPressed() {
        volumeLevel--;
        System.out.println("Volume at: " + volumeLevel);
    }
}
