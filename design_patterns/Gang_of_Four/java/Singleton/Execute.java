package Singleton;

public class Execute {

    public static void main(String[] args) {

        Singleton instanceOne = Singleton.getInstance();
        System.out.println("Instance ID : " + System.identityHashCode(instanceOne));

        Singleton instanceTwo = Singleton.getInstance();
        System.out.println("Instance ID : " + System.identityHashCode(instanceTwo));
    }
}
