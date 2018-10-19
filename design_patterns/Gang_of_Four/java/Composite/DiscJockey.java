package Composite;

public class DiscJockey {

    private SongComponent songList;

    public DiscJockey(SongComponent songList) {
        this.songList = songList;
    }

    // Calls the displaySongInfo() on every Song
    // or SongGrop stored in songList

    public void getSongList() {
        songList.displaySongInfo();
    }
}