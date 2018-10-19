package Strategy;

class Bird extends Animals {

    Bird() {
        super();

        flyingType = new ItFlys();
    }

}
