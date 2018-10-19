package Bridge;

public class DvdRemote extends RemoteButton {

    private boolean isPlaying = false;

    public DvdRemote(EntertainmentDevice device) {
        super(device);
    }

    @Override
    public void buttonNinePressed() {
        isPlaying = !isPlaying;
        System.out.println("DVD is Playing: " + isPlaying);
    }
}
