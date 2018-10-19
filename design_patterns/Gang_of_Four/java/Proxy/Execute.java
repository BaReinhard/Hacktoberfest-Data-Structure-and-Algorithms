package Proxy;

public class Execute {

    public static void main(String[] args) {
        Image proxyImage = new ProxyImage("myfile.jpg");

        // Inaccessible method (since proxyImage is of type Image)
        // proxyImage.showFileSecretAttributes();

        // image will be loaded from disk
        proxyImage.display();

        System.out.println();

        // image has been cached
        // image will not be loaded from disk
        proxyImage.display();
    }
}
