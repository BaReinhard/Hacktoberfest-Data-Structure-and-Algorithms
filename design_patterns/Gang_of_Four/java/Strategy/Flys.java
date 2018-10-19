package Strategy;

public interface Flys {
    String fly();
}

class ItFlys implements Flys {

    @Override
    public String fly() {
        return "Flying high";
    }
}

class CantFly implements Flys {

    @Override
    public String fly() {
        return "Can't fly";
    }
}