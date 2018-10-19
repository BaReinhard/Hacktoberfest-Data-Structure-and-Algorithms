package Mediator;

import java.util.ArrayList;

public class StockMediator implements Mediator {

    private ArrayList<Colleague> colleagues;
    private ArrayList<StockOffer> stockBuyOffers;
    private ArrayList<StockOffer> stockSaleOffers;

    private int colleagueCodes = 0;

    public StockMediator() {
        colleagues = new ArrayList<Colleague>();
        stockBuyOffers = new ArrayList<StockOffer>();
        stockSaleOffers = new ArrayList<StockOffer>();
    }

    public void showStockOfferings() {
        System.out.println("\nStocks for Sale");

        for (StockOffer offer : stockSaleOffers)
            System.out.println(offer.getStockShares() + " of " + offer.getStockSymbol());

        System.out.println("\nStocks Buy Offers");

        for (StockOffer offer : stockBuyOffers)
            System.out.println(offer.getStockShares() + " of " + offer.getStockSymbol());
    }

    @Override
    public void addColleague(Colleague colleague) {
        colleagues.add(colleague);
        colleagueCodes++;
        colleague.setColleagueCode(colleagueCodes);
    }

    @Override
    public void saleOffer(String stock, int shares, int colleagueCode) {

        boolean stockSold = false;

        for (StockOffer offer : stockBuyOffers) {

            if ((offer.getStockSymbol() == stock) &&
                    (offer.getStockShares() == shares)) {

                System.out.println(shares + " shares of " + stock +
                        " sold to colleague code : " + offer.getColleagueCode());

                stockBuyOffers.remove(offer);
                stockSold = true;
                break;
            }
        }

        if (!stockSold) {

            System.out.println(shares + " shares of " + stock + " added to inventory");

            StockOffer newOffer = new StockOffer(shares, stock, colleagueCode);
            stockSaleOffers.add(newOffer);
        }
    }

    @Override
    public void buyOffer(String stock, int shares, int colleagueCode) {

        boolean stockBought = false;

        for (StockOffer offer : stockSaleOffers) {

            if ((offer.getStockSymbol() == stock) &&
                    (offer.getStockShares() == shares)) {

                System.out.println(shares + " shares of " + stock +
                        " bought by colleague code : " + offer.getColleagueCode());

                stockSaleOffers.remove(offer);
                stockBought = true;
                break;
            }
        }

        if (!stockBought) {

            System.out.println(shares + " shares of " + stock + " added to inventory");

            StockOffer newOffer = new StockOffer(shares, stock, colleagueCode);
            stockBuyOffers.add(newOffer);
        }
    }
}
