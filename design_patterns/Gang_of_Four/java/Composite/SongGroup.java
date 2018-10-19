package Composite;

import java.util.ArrayList;

public class SongGroup extends SongComponent {

    // Contains any Songs or SongGroups that are added
    // to this ArrayList

    private ArrayList<SongComponent> songComponents;

    private String groupName;
    private String groupDescription;

    public SongGroup(String groupName, String groupDescription) {
        this.groupName = groupName;
        this.groupDescription = groupDescription;

        songComponents = new ArrayList<>();
    }

    public String getGroupName() {
        return groupName;
    }

    public String getGroupDescription() {
        return groupDescription;
    }

    @Override
    public void add(SongComponent songComponent) {
        songComponents.add(songComponent);
    }

    @Override
    public void remove(SongComponent songComponent) {
        songComponents.remove(songComponent);
    }

    @Override
    public SongComponent getComponent(int componentIndex) {
        return songComponents.get(componentIndex);
    }

    @Override
    public void displaySongInfo() {
        System.out.println(getGroupName() + " " + getGroupDescription() + "\n");

        // Cycles through and prints any Songs or SongGroups added
        // to this SongGroups ArrayList songComponents

        for (SongComponent songComponent : songComponents)
            songComponent.displaySongInfo();
    }
}
