package Memento;

public class Memento {

    // Memento Design Pattern
    // Stores an object's state at a point in time
    // so it can be returned to that state later. It
    // simply allows you to undo/redo changes on an Object

    // The article stored in memento Object

    private String article;

    // Save a new article String to the memento Object

    public Memento(String article) {
        this.article = article;
    }

    // Return the value stored in article

    public String getSavedArticle() {
        return article;
    }
}
