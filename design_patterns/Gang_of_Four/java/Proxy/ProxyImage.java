package Proxy;

public class ProxyImage implements Image {

    private RealImage realImage;
    private String fileName;

    public ProxyImage(String fileName) {
        this.fileName = fileName;
    }

    @Override
    public void display() {
        // Use case 2 - Caching

        if (realImage == null)
            realImage = new RealImage(fileName);

        // Use case 3 - Remote Proxy

        realImage.display();
    }
}
