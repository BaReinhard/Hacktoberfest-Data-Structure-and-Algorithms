package Prototype;

public class Execute {

    public static void main(String[] args) {
        CloneFactory animalMaker = new CloneFactory();

        Sheep sally = new Sheep();

        Sheep clonedSheep = (Sheep) animalMaker.getClone(sally);

        System.out.println(sally);
        System.out.println(clonedSheep);

        System.out.println("Sally hashcode: " + System.identityHashCode(sally));
        System.out.println("ClonedSheep hashcode: " + System.identityHashCode(clonedSheep));
    }
}
