package Bridge;

public class Execute {

    public static void main(String[] args) {
        RemoteButton tvRemote1 = new TvRemoteMute(new TvDevice(1, 5));
        RemoteButton tvRemote2 = new TvRemotePause(new TvDevice(1, 5));
        RemoteButton dvdRemote = new DvdRemote(new DvdDevice(1, 3));

        System.out.println("Test Tv with mute");
        tvRemote1.buttonFivePressed();
        tvRemote1.buttonSixPressed();
        tvRemote1.buttonNinePressed();
        tvRemote1.deviceFeedback();

        System.out.println("\n\nTest Tv with pause");
        tvRemote2.buttonFivePressed();
        tvRemote2.buttonSixPressed();
        tvRemote2.buttonNinePressed();
        tvRemote2.deviceFeedback();

        System.out.println("\n\nTest DVD");
        dvdRemote.buttonFivePressed();
        dvdRemote.buttonSixPressed();
        dvdRemote.buttonNinePressed();
        dvdRemote.deviceFeedback();
    }
}
