package Bridge;

public class TvRemotePause extends RemoteButton {

    // Refined Abstraction
    // If I decide I want to further extend the remote I can

    public TvRemotePause(EntertainmentDevice device) {
        super(device);
    }

    @Override
    public void buttonNinePressed() {
        System.out.println("TV was Paused");
    }

}
