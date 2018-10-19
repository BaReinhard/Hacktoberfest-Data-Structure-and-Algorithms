package Singleton;

public class Singleton {

    private static Singleton firstInstance = null;

    private Singleton() {
    }

    public static Singleton getInstance() {

        //Lazy Instantiation - If the instance isn't needed it isn't created

        if (firstInstance == null)
            firstInstance = new Singleton();

        return firstInstance;
    }
}
