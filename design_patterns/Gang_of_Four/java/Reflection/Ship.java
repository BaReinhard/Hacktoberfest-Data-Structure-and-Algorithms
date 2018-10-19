package Reflection;

public class Ship {

    private String name;

    private String idcode = "This is idcode";

    private String getPrivateMethod() {
        return "How did you get this!";
    }

    private String getOtherPrivateMethod(int thisInt, String thatString) {
        return "How did you get here " + thisInt + " , " + thatString;
    }

    // Setter
    public void setName(String name) {
        this.name = name;
    }

    // Getter
    public String getName() {
        return name;
    }

    // Constructors
    public Ship(int number, String randomString) {
        System.out.println("You sent: " + number + " , " + randomString);
    }

    public Ship(Object o) {
        System.out.println("You sent: " + o);
    }

    public Ship() {
    }
}
