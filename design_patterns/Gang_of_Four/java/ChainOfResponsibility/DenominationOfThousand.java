package ChainOfResponsibility;

public class DenominationOfThousand implements Chain {

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

        int notesOfThousand = amount / Chain.THOUSAND;

        if (notesOfThousand == 0)
            nextInChain.calculateDenominations(amount);
        else {
            System.out.println(Chain.THOUSAND + " * " + notesOfThousand);

            int remainingAmount = amount % Chain.THOUSAND;

            if (remainingAmount > 0)
                nextInChain.calculateDenominations(remainingAmount);
        }
    }
}
