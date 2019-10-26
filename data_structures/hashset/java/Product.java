public class Product{
    //member variable declaration
    private int id;
    private float price;
    private String name;
    private static final int HASH_CONSTANT = 31;

    public Product(int id, String name, float price) {
        this.id = id;
        this.name = name;
        this.price = price;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public float getPrice() {
        return price;
    }

    public void setPrice(float price) {
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    //overriding Object class methods
    @Override
    public String toString() {
        return id + " " + name + " " + price;
    }

    @Override
    public int hashCode() {
        int hash = (HASH_CONSTANT * id) + name.length() + (int) price;
        return hash;
    }

    @Override
    public boolean equals(Object obj) {
        //downcasting
        Product product = (Product) obj;

        if (this.id == product.id && this.name.equals(product.name) && this.price == product.price) {
            return true;
        }

        return false;
    }
}