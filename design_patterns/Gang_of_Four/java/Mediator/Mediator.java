package Mediator;

public interface Mediator {

    void saleOffer(String stock, int shares, int colleagueCode);

    void buyOffer(String stock, int shares, int colleagueCode);

    void addColleague(Colleague colleague);
}
