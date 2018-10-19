package Iterator;

import java.util.Arrays;
import java.util.Iterator;

public class SongsOfThe80s implements SongIterator {

    private SongInfo bestSongs[];
    private int arrayCounter = 0;

    public SongsOfThe80s() {
        bestSongs = new SongInfo[3];

        addSong("Roam", "B 52s", 1989);
        addSong("Cruel Summer", "Bananarama", 1984);
        addSong("Head Over Heels", "Tears For Fears", 1985);
    }

    // Add a SongInfo Object to the array and increment to the next position

    private void addSong(String songName, String bandName, int yearReleased) {
        SongInfo songInfo = new SongInfo(songName, bandName, yearReleased);
        bestSongs[arrayCounter++] = songInfo;
    }

    public SongInfo[] getBestSongs() {
        return bestSongs;
    }

    // By adding this method I'll be able to treat all
    // collections the same

    @Override
    public Iterator createIterator() {
        return Arrays.asList(bestSongs).iterator();
    }
}
