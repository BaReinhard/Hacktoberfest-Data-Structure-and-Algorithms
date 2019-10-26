import java.util.HashSet;

public class ProductSetDemo{
    public static void main(String... args){
        Product product1 = new Product(1,"Samsung Galaxy 10",20000f);
        Product product2 = new Product(2,"Samsung Galaxy S",90000f);
        Product product3 = new Product(1,"Samsung Galaxy A series",80000f);
        Product product4 = new Product(1,"Samsung Galaxy A series",80000f);

        HashSet<Product> products = new HashSet<>();

        //add() internally calls hashCode() and equals(),hence it is important that we override them so
        // that no two objects can exist with same values.
        products.add(product1);
        products.add(product2);
        products.add(product3);

        products.add(product4);

        System.out.println(products);
    }
}