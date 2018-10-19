package ChainOfResponsibility;

public class Execute {

    public static void main(String[] args) {

        // Here I define all of the objects in the chain

        Chain chainThousand = new DenominationOfThousand();
        Chain chainHundred = new DenominationOfHundred();
        Chain chainTen = new DenominationOfTen();
        Chain chainOne = new DenominationOfOne();

        // Here I tell each object where to forward the
        // data if it can't process the request

        chainThousand.setNextInChain(chainHundred);
        chainHundred.setNextInChain(chainTen);
        chainTen.setNextInChain(chainOne);

        // Define the data and send it to the first
        // Object in the chain

        chainThousand.calculateDenominations(2254);
        System.out.println();
        chainThousand.calculateDenominations(109);
        System.out.println();
        chainThousand.calculateDenominations(0);
    }
}
