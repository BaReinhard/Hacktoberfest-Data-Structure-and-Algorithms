package Memento;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Execute extends JFrame {

    // The Memento design pattern provides a way to store previous
    // states of an Object easily. It has 3 main classes.
    // 1. Memento: The basic object that is stored in different states.
    // 2. Originator: Sets and Gets values from the currently targeted
    // Memento, creates new Mementos and assigns current values to them.
    // 3. Caretaker: Holds an ArrayList that contains all previous versions
    // of the Memento. It can store and retrieve stored Mementos.

    public static void main(String[] args) {
        new Execute();
    }

    private JButton saveBut, undoBut, redoBut;
    private JTextArea theArticle = new JTextArea(40, 60);

    // Create a caretaker that contains the ArrayList
    // with all the articles in it. It can add and
    // retrieve articles from the ArrayList

    private Caretaker caretaker = new Caretaker();

    // The originator sets the value for the article,
    // creates a new memento with a new article, and
    // gets the article stored in the current memento

    private Originator originator = new Originator();

    private int saveFiles = 0, currentArticle = 0;

    public Execute() {
        // Set basic information for the panel that will
        // hold all the GUI elements

        this.setSize(750, 780);
        this.setTitle("Memento Design Pattern");
        this.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        JPanel panel1 = new JPanel();

        panel1.add(new JLabel("Article"));
        panel1.add(theArticle);

        // Add the buttons & ButtonListeners to the panel

        ButtonListener saveListener = new ButtonListener();
        ButtonListener undoListener = new ButtonListener();
        ButtonListener redoListener = new ButtonListener();

        saveBut = new JButton("Save");
        saveBut.addActionListener(saveListener);

        undoBut = new JButton("Undo");
        undoBut.addActionListener(undoListener);

        redoBut = new JButton("Redo");
        redoBut.addActionListener(redoListener);

        panel1.add(saveBut);
        panel1.add(undoBut);
        panel1.add(redoBut);

        // Add panel to the frame that shows on screen

        this.add(panel1);
        this.setVisible(true);
    }

    class ButtonListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent ae) {

            if (ae.getSource() == saveBut) {

                // Get text in JTextArea

                String textIntextArea = theArticle.getText();

                // Set the value for the current memento

                originator.setArticle(textIntextArea);

                // Add new article to the ArrayList

                caretaker.addMemento(originator.storeInMemento());

                // saveFiles monitors how many articles are saved
                // currentArticle monitors the current article displayed

                saveFiles++;
                currentArticle++;

                System.out.println("Save Files " + saveFiles);

                // Make undo clickable

                undoBut.setEnabled(true);
            } else if (ae.getSource() == undoBut) {

                if (currentArticle > 0) {

                    // Decrement to the current article displayed

                    currentArticle--;

                    // Get the older article saved and display it in JTextArea
                    String textBoxString = originator.restoreFromMemento(caretaker.getMemento(currentArticle));
                    theArticle.setText(textBoxString);

                    // Make redo clickable

                    redoBut.setEnabled(true);

                } else {
                    // Don't allow user to click Undo
                    undoBut.setEnabled(false);
                }
            } else if (ae.getSource() == redoBut) {

                if ((saveFiles - 1) > currentArticle) {
                    // Increment to the current article displayed

                    currentArticle++;

                    // Get the newer article saved and display it in JTextArea

                    String textBoxString = originator.restoreFromMemento(caretaker.getMemento(currentArticle));
                    theArticle.setText(textBoxString);

                    // Make undo clickable

                    undoBut.setEnabled(true);

                } else {
                    // Don't allow user to click Redo

                    redoBut.setEnabled(false);
                }
            }
        }
    }
}
