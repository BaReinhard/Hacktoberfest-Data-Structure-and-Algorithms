package Command;

//Create a request class

public class Stock {

    private String name;
    private int qty;

    Stock(String name, int qty) {
        this.name = name;
        this.qty = qty;
    }

    void buy() {
        System.out.println("Stock : [ Name: " +
                name + " , Qty: " +
                qty + " ] bought");
    }

    void sell() {
        System.out.println("Stock : [ Name: " +
                name + " , Qty: " +
                qty + " ] sold");
    }
}
