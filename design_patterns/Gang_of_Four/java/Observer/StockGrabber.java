package Observer;

import java.util.ArrayList;

public class StockGrabber implements Subject {

    private ArrayList<Observer> observers;
    private double ibmPrice;
    private double aaplPrice;

    StockGrabber() {
        observers = new ArrayList<Observer>();
    }

    @Override
    public void register(Observer o) {
        observers.add(o);
    }

    @Override
    public void unregister(Observer o) {
        int observerIndex = observers.indexOf(o);
        System.out.println("Observer " + (observerIndex + 1) + " deleted");
        observers.remove(observerIndex);
    }

    @Override
    public void notifyObserver() {

        for (Observer observer : observers) {
            observer.update(ibmPrice, aaplPrice);
        }
    }

    void setIBMPrice(double ibmPrice) {
        this.ibmPrice = ibmPrice;
        notifyObserver();
    }

    void setAAPLPrice(double aaplPrice) {
        this.aaplPrice = aaplPrice;
        notifyObserver();
    }
}
