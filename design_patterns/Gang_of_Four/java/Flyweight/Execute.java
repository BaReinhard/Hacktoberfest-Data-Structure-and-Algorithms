package Flyweight;

public class Execute {
    // The Flyweight design pattern is used when you need to
    // create a large number of similar objects

    // To reduce memory this pattern shares Objects that are
    // the same rather than creating new ones

    private static String colors[] = {"black", "blue", "green", "magenta", "yellow"};

    public static void main(String[] args) {

        for (int i = 0; i < 10; i++) {

            Circle circle = (Circle) ShapeFactory.getCircle(getRandomColor());
            circle.setX(getRandomSize());
            circle.setY(getRandomSize());
            circle.setRadius(getRandomRadius());
            circle.draw();
        }
    }

    private static String getRandomColor() {
        int index = (int) (Math.random() * colors.length);
        return colors[index];
    }

    private static int getRandomSize() {
        return (int) (Math.random() * 100);
    }

    private static int getRandomRadius() {
        return (int) (Math.random() * 50);
    }
}
