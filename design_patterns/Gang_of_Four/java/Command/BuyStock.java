package Command;

public class BuyStock implements Order {
    //Concrete class implementing the Order interface

    private Stock stock;

    BuyStock(Stock stock) {
        this.stock = stock;
    }

    @Override
    public void execute() {
        stock.buy();
    }
}
