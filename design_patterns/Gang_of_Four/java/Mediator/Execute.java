package Mediator;

public class Execute {

    /*
        The Mediator design pattern is used to handle communication
        between related objects (Colleagues). All communication is
        handled by a Mediator Object and the Colleagues don’t need
        to know anything about each other to work together.
    */


    public static void main(String[] args) {
        StockMediator stockMediator = new StockMediator();

        GormanSlacks broker1 = new GormanSlacks(stockMediator);
        JTPoorman broker2 = new JTPoorman(stockMediator);
        System.out.println();

        broker1.saleOffer("MSFT", 100);
        broker1.saleOffer("GOOG", 50);

        broker2.saleOffer("MSFT", 200);
        broker2.saleOffer("NRG", 10);

        broker1.buyOffer("NRG", 10);
        broker1.buyOffer("APPL", 30);

        stockMediator.showStockOfferings();
    }
}
