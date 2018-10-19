package Iterator;

import java.util.ArrayList;
import java.util.Iterator;

public class SongsOfThe70s implements SongIterator {

    private ArrayList<SongInfo> bestSongs;

    public SongsOfThe70s() {
        bestSongs = new ArrayList<SongInfo>();

        addSong("Imagine", "John Lennon", 1971);
        addSong("American Pie", "Don McLean", 1971);
        addSong("I Will Survive", "Gloria Gaynor", 1979);
    }

    // Add a SongInfo object to the end of the ArrayList

    private void addSong(String songName, String bandName, int yearReleased) {
        SongInfo songInfo = new SongInfo(songName, bandName, yearReleased);
        bestSongs.add(songInfo);
    }

    public ArrayList<SongInfo> getBestSongs() {
        return bestSongs;
    }

    // By adding this method I'll be able to treat all
    // collections the same

    @Override
    public Iterator createIterator() {
        return bestSongs.iterator();
    }
}
