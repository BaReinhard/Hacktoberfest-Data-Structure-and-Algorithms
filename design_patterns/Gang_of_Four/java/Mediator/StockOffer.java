package Mediator;

public class StockOffer {

    private int stockShares;
    private String stockSymbol;
    private int colleagueCode;

    public StockOffer(int stockShares, String stockSymbol, int colleagueCode) {
        this.stockShares = stockShares;
        this.stockSymbol = stockSymbol;
        this.colleagueCode = colleagueCode;
    }

    public int getStockShares() {
        return stockShares;
    }

    public String getStockSymbol() {
        return stockSymbol;
    }

    public int getColleagueCode() {
        return colleagueCode;
    }
}
