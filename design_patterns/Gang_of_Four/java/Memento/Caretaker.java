package Memento;

import java.util.ArrayList;

public class Caretaker {

    // Where all mementos are saved

    private ArrayList<Memento> savedArticles;

    public Caretaker() {
        savedArticles = new ArrayList<Memento>();
    }

    // Adds memento to the ArrayList

    public void addMemento(Memento memento) {
        savedArticles.add(memento);
    }

    // Gets the memento requested from the ArrayList

    public Memento getMemento(int index) {
        return savedArticles.get(index);
    }
}
