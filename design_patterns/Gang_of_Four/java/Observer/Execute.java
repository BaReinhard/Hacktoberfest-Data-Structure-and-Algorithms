package Observer;

public class Execute {

    public static void main(String[] args) {
        StockGrabber stockGrabber = new StockGrabber();

        StockObserver observer1 = new StockObserver(stockGrabber);
        stockGrabber.setIBMPrice(100.00);
        stockGrabber.setAAPLPrice(200.00);

        StockObserver observer2 = new StockObserver(stockGrabber);
        stockGrabber.setIBMPrice(300.00);
        stockGrabber.setAAPLPrice(400.00);

        stockGrabber.unregister(observer1);

        stockGrabber.setIBMPrice(500.00);
        stockGrabber.setAAPLPrice(600.00);

    }
}
