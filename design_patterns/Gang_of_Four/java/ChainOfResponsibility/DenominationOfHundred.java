package ChainOfResponsibility;

public class DenominationOfHundred implements Chain {

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

        int notesOfHundred = amount / Chain.HUNDRED;

        if (notesOfHundred == 0)
            nextInChain.calculateDenominations(amount);
        else {
            System.out.println(Chain.HUNDRED + " * " + notesOfHundred);

            int remainingAmount = amount % Chain.HUNDRED;

            if (remainingAmount > 0)
                nextInChain.calculateDenominations(remainingAmount);
        }
    }
}
