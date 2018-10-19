package Iterator;

import java.util.ArrayList;
import java.util.Hashtable;
import java.util.Iterator;

public class DiscJockey {

    private SongsOfThe70s songs70s;
    private SongsOfThe80s songs80s;
    private SongsOfThe90s songs90s;

    private SongIterator iter70sSongs;
    private SongIterator iter80sSongs;
    private SongIterator iter90sSongs;

    // OLD WAY

   /* public DiscJockey(SongsOfThe70s songs70s, SongsOfThe80s songs80s, SongsOfThe90s songs90s) {
        this.songs70s = songs70s;
        this.songs80s = songs80s;
        this.songs90s = songs90s;
    }

    public void showTheSongs() {
        // Because the SongInfo Objects are stored in different
        // collections everything must be handled on an individual
        // basis. This is BAD!

        System.out.println("Songs of the 70s -");

        ArrayList<SongInfo> arraylist70sSings = songs70s.getBestSongs();

        for (SongInfo songInfo : arraylist70sSings) {
            System.out.println(songInfo.getSongName() + " , " +
                    songInfo.getBandName() + " , " +
                    songInfo.getYearReleased());
        }

        System.out.println("\nSongs of the 80s -");

        SongInfo[] array80sSongs = songs80s.getBestSongs();
        for (SongInfo songInfo : array80sSongs) {
            System.out.println(songInfo.getSongName() + " , " +
                    songInfo.getBandName() + " , " +
                    songInfo.getYearReleased());
        }

        System.out.println("\nSongs of the 90s -");

        Hashtable<Integer, SongInfo> hashtable90sSongs = songs90s.getBestSongs();

        for (SongInfo songInfo : array80sSongs) {
            System.out.println(songInfo.getSongName() + " , " +
                    songInfo.getBandName() + " , " +
                    songInfo.getYearReleased());
        }
    }*/

    // NEW WAY Initialize the iterators

    public DiscJockey(SongIterator iter70sSongs, SongIterator iter80sSongs, SongIterator iter90sSongs) {
        this.iter70sSongs = iter70sSongs;
        this.iter80sSongs = iter80sSongs;
        this.iter90sSongs = iter90sSongs;
    }

    // Now that I can treat everything as an Iterator. It cleans up
    // the code while allowing me to treat all collections as one

    public void showTheSongs2() {
        System.out.println("NEW WAY WITH ITERATOR\n");

        System.out.println("Songs of the 70s -");
        printTheSongs(iter70sSongs.createIterator());

        System.out.println("\nSongs of the 80s -");
        printTheSongs(iter80sSongs.createIterator());

        System.out.println("\nSongs of the 90s -");
        printTheSongs(iter90sSongs.createIterator());
    }

    private void printTheSongs(Iterator iterator) {
        while (iterator.hasNext()) {
            SongInfo songInfo = (SongInfo) iterator.next();
            System.out.println(songInfo.getSongName() + " , " +
                    songInfo.getBandName() + " , " +
                    songInfo.getYearReleased());
        }
    }
}
