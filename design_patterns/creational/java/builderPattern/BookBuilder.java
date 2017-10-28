public class BookBuilder
{
   private String name;
   private String author;
   private String language;
   private String ISBN;
   private double quantity;

   public BookBuilder setName(String name) {
      this.name = name;
      return this;
   }

   public BookBuilder setAuthor(String author) {
      this.author = author;
      return this;
   }

   public BookBuilder setLanguage(String language) {
      this.language = language;
      return this;
   }

   public BookBuilder setISBN(String ISBN) {
      this.ISBN = ISBN;
      return this;
   }

   public BookBuilder setQuantity(double quantity) {
      this.quantity = quantity;
      return this;
   }

   public Book buildBook() {
      return new Book(name, author, language, ISBN, quantity);
   }
}

class Book
{
   private String name;
   private String author;
   private String language;
   private String ISBN;
   private double quantity;

   public Book(String name, String author, String language, String ISBN, double quantity){
      this.name = name;
      this.author = author;
      this.language = language;
      this.ISBN = ISBN;
      this.quantity = quantity;
   }
}