package Command;

public class SellStock implements Order {
    //Concrete class implementing the Order interface

    private Stock stock;

    SellStock(Stock stock) {
        this.stock = stock;
    }

    @Override
    public void execute() {
        stock.sell();
    }
}
