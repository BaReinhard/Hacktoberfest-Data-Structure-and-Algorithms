package Strategy;

class Animals {
    Flys flyingType;

    String tryToFly() {
        return flyingType.fly();
    }

    public void setFlyingType(Flys flyingType) {
        this.flyingType = flyingType;
    }
}
