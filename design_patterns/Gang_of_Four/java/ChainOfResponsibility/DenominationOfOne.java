package ChainOfResponsibility;

public class DenominationOfOne implements Chain {

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

        int notesOfOne = amount / Chain.ONE;

        if (notesOfOne == 0)
            System.out.println("Enter amount > 0.\nDenominations cannot be created!");
        else
            System.out.println(Chain.ONE + " * " + notesOfOne);
    }
}
