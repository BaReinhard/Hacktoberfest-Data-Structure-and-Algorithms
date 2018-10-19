package Iterator;

public class Execute {

    public static void main(String[] args) {

        SongsOfThe70s songs70s = new SongsOfThe70s();
        SongsOfThe80s songs80s = new SongsOfThe80s();
        SongsOfThe90s songs90s = new SongsOfThe90s();

        DiscJockey dj = new DiscJockey(songs70s, songs80s, songs90s);
        // OLD WAY
        //dj.showTheSongs();
        // NEW WAY
        dj.showTheSongs2();
    }
}
