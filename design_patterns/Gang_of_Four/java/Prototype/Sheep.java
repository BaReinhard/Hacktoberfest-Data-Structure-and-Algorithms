package Prototype;

public class Sheep implements Animal {

    public Sheep() {
        System.out.println("Sheep is made");
    }

    @Override
    public Animal makeCopy() {
        System.out.println("Sheep is being cloned");

        Sheep sheepObject = null;

        try {
            sheepObject = (Sheep) super.clone();
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }

        return sheepObject;
    }

    @Override
    public String toString(){
        return "Dolly is here! Baaaaaa!";
    }
}
