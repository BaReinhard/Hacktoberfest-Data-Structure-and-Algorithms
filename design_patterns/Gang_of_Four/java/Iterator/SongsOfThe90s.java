package Iterator;

import org.apache.batik.dom.util.HashTable;

import java.util.ArrayList;
import java.util.Hashtable;
import java.util.Iterator;

public class SongsOfThe90s implements SongIterator {

    private Hashtable<Integer, SongInfo> bestSongs;
    private int hashkey = 0;

    public SongsOfThe90s() {
        bestSongs = new Hashtable<Integer, SongInfo>();

        addSong("Losing My Religion", "REM", 1991);
        addSong("Creep", "Radiohead", 1993);
        addSong("Walk on the Ocean", "Toad The Wet Sprocket", 1991);
    }

    // Add a new SongInfo Object to the Hashtable and then increment
    // the Hashtable key

    private void addSong(String songName, String bandName, int yearReleased) {
        SongInfo songInfo = new SongInfo(songName, bandName, yearReleased);
        bestSongs.put(hashkey++, songInfo);
    }

    public Hashtable<Integer, SongInfo> getBestSongs() {
        return bestSongs;
    }

    // By adding this method I'll be able to treat all
    // collections the same

    @Override
    public Iterator createIterator() {
        return bestSongs.values().iterator();
    }
}
