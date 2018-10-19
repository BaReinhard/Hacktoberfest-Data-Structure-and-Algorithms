package Flyweight;

import java.util.HashMap;

public class ShapeFactory {

    // This factory only creates a new shape if it
    // uses a color not previously used

    // Intrinsic State ( state-independent ): color
    // Extrinsic State ( state-dependent ): X & Y Values

    private static final HashMap<String, Shape> shapeMap = new HashMap<>();

    public static Shape getCircle(String color) {

        Circle circle = (Circle) shapeMap.get(color);

        if (circle == null) {
            System.out.println("Creating circle of color : " + color);
            circle = new Circle(color);
            shapeMap.put(color, circle);
        }

        return circle;
    }
}
