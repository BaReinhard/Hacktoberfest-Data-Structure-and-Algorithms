package Bridge;

public class TvRemoteMute extends RemoteButton {

    // Refined Abstraction
    // If I decide I want to further extend the remote I can

    public TvRemoteMute(EntertainmentDevice device) {
        super(device);
    }

    @Override
    public void buttonNinePressed() {
        System.out.println("TV was Muted");
    }
}
