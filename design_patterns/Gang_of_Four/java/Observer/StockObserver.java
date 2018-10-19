package Observer;

public class StockObserver implements Observer {

    private double ibmPrice;
    private double aaplPrice;

    private static int observerIDTracker = 0;
    private int observerID;

    private Subject stockGrabber;

    StockObserver(Subject stockGrabber) {
        this.stockGrabber = stockGrabber;
        this.observerID = ++observerIDTracker;

        System.out.println("New Observer : " + this.observerID);
        this.stockGrabber.register(this);
    }

    @Override
    public void update(double ibmPrice, double aaplPrice) {
        this.ibmPrice = ibmPrice;
        this.aaplPrice = aaplPrice;

        printThePrices();
    }

    private void printThePrices() {
        System.out.println(observerID +
                "\nIBM: " + ibmPrice +
                "\nAAPL: " + aaplPrice +
                "\n");
    }


}
