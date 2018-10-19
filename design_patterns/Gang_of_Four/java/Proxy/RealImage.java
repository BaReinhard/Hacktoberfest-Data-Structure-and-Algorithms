package Proxy;

public class RealImage implements Image {

    private String fileName;

    public RealImage(String fileName) {
        this.fileName = fileName;
        loadFromDisk(fileName);
    }

    private void loadFromDisk(String fileName) {
        System.out.println("Loading " + fileName);
    }

    // Use case 1 - Protection Proxy (Controlled Access)

    void showFileSecretAttributes() {
        System.out.println("Opened file secret attributes");
    }

    @Override
    public void display() {
        System.out.println("Displaying " + fileName);
    }
}
