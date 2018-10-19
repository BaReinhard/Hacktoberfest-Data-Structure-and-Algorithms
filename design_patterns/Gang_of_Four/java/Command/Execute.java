package Command;

public class Execute {

    public static void main(String[] args) {

        Stock stock = new Stock("GoogStock", 100);

        BuyStock buyStock = new BuyStock(stock);
        SellStock sellStock = new SellStock(stock);

        Broker broker = new Broker();
        broker.placeOrder(buyStock);
        broker.placeOrder(sellStock);
        broker.processOrders();
    }
}
