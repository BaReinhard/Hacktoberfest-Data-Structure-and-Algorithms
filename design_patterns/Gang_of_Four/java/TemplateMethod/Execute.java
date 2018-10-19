package TemplateMethod;

public class Execute {

    public static void main(String[] args) {
        ItalianHoagie italianHoagie = new ItalianHoagie();
        VeggieHoagie veggieHoagie = new VeggieHoagie();

        System.out.println("ITALIAN HOAGIE - ");
        italianHoagie.makeSandwich();
        System.out.println();

        System.out.println("VEGGIE HOAGIE - ");
        veggieHoagie.makeSandwich();
    }
}
