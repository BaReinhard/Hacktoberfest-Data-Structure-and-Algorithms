package ChainOfResponsibility;

public class DenominationOfTen implements Chain {

    private Chain nextInChain;

    // Defines the next Object to receive the
    // data if this one can't use it

    @Override
    public void setNextInChain(Chain nextInChain) {
        this.nextInChain = nextInChain;
    }

    // Tries to calculate the data, or passes it
    // to the Object defined in method setNextInChain()

    @Override
    public void calculateDenominations(int amount) {

        int notesOfTen = amount / Chain.TEN;

        if (notesOfTen == 0)
            nextInChain.calculateDenominations(amount);
        else {
            System.out.println(Chain.TEN + " * " + notesOfTen);

            int remainingAmount = amount % Chain.TEN;

            if (remainingAmount > 0)
                nextInChain.calculateDenominations(remainingAmount);
        }
    }
}
