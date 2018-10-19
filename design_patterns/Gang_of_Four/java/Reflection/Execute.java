package Reflection;

import java.lang.reflect.*;

public class Execute {

    public static void main(String[] args) {

        Class reflectClass = Ship.class;

        String className = reflectClass.getName();
        System.out.println("ClassName: " + className);

        int classModifiers = reflectClass.getModifiers();
        System.out.println("Class Modifier - isPublic: " + Modifier.isPublic(classModifiers));
        // isAbstract, isFinal, isInterface, isPrivate, isProtected,
        // isStatic, isStrict, isSynchronized, isVolatile

        Class classSuper = reflectClass.getSuperclass();
        System.out.println("SuperClass: " + classSuper.getName() + "\n");

        // getMethods - Methods of superclass of reflectClass
        // getDeclaredMethods - Methods of reflectClass
        Method classMethods[] = reflectClass.getMethods();
        for (Method method : classMethods) {
            System.out.println("Method Name: " + method.getName());

            if (method.getName().startsWith("get"))
                System.out.println("is a getter method");
            else if (method.getName().startsWith("set"))
                System.out.println("is a setter method");

            System.out.println("Return type: " + method.getReturnType());

            Class parameterType[] = method.getParameterTypes();
            if (parameterType.length != 0)
                System.out.println("Parameters:");

            for (Class parameter : parameterType)
                System.out.println(parameter.getName());

            System.out.println();
        }


        // access class constructors

        Constructor constructor = null;
        Object constructorObject = null;

        // To return an array of constructors instead, do this :
        // Constructor[] constructors = reflectClass.getConstructors();

        // If the constructor receives a String you'd use the
        // parameter - new Class[]{String.class}
        // For an object parameter, use new Class[]{ObjectClass.class}
        // For others use int.class, double.class, etc.

        try {
            constructor = reflectClass.getConstructor(new Class[]{Object.class});

            constructorObject = reflectClass.getConstructor(int.class, String.class)
                    .newInstance(12, "Random String");

        } catch (NoSuchMethodException | IllegalAccessException | InstantiationException | InvocationTargetException e) {
            e.printStackTrace();
        }


        // Return the parameters of a constructor

        assert constructor != null;
        Class constructorParameters[] = constructor.getParameterTypes();
        for (Class parameter : constructorParameters)
            System.out.println("Constructor Parameter: " + parameter.getName());

        Ship newShip = null;
        try {
            newShip = (Ship) constructor.newInstance(new Object());
            System.out.println("\n");
        } catch (IllegalAccessException | InstantiationException | InvocationTargetException e) {
            e.printStackTrace();
        }

        // Now I can call methods in the Ship object
        newShip.setName("NewName");
        System.out.println("Ship Name: " + newShip.getName());


        try {
            // Access private fields
            Field privateStringidcode = null;

            Ship shipPrivate = new Ship();
            // Define the private field you want to access
            privateStringidcode = Ship.class.getDeclaredField("idcode");
            // Shuts down security allowing you to access private fields
            privateStringidcode.setAccessible(true);

            String valueOfName = (String) privateStringidcode.get(shipPrivate);
            System.out.println("Ship Private idcode: " + valueOfName);


            // Access private method
            String methodname = "getPrivateMethod";

            Method privateMethod = Ship.class.getDeclaredMethod(methodname, (Class<?>[]) null);
            // Shuts down security allowing you to access private methods
            privateMethod.setAccessible(true);

            String privateReturnVal = (String) privateMethod.invoke(shipPrivate, (Object[]) null);
            System.out.println("Ship Private Method: " + privateReturnVal);


            // Execute a method that has parameters
            Class[] methodParameters = new Class[]{Integer.TYPE, String.class};
            Object[] params = new Object[]{new Integer(10), "Random"};

            privateMethod = Ship.class.getDeclaredMethod("getOtherPrivateMethod", methodParameters);
            // Shuts down security allowing you to access private methods
            privateMethod.setAccessible(true);

            privateReturnVal = (String) privateMethod.invoke(shipPrivate, params);
            System.out.println("EnemyShip Other Private Method: " + privateReturnVal);

        } catch (IllegalAccessException | NoSuchFieldException | NoSuchMethodException | InvocationTargetException e) {
            e.printStackTrace();
        }

    }
}
