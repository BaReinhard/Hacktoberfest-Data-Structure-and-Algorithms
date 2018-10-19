package MVC;

import javax.swing.*;
import java.awt.event.ActionListener;

public class CalculatorView extends JFrame {

    // This is the View
    // Its only job is to display what the user sees
    // It performs no calculations, but instead passes
    // information entered by the user to whomever needs
    // it.

    private JTextField firstNumber = new JTextField(10);
    private JLabel additionLabel = new JLabel("+");
    private JTextField secondNumber = new JTextField(10);
    private JButton calculateButton = new JButton("Calculate");
    private JTextField calcSolution = new JTextField(10);

    public CalculatorView() {
        // Sets up the view and adds the components

        JPanel calcPanel = new JPanel();

        this.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        this.setSize(600, 200);

        calcPanel.add(firstNumber);
        calcPanel.add(additionLabel);
        calcPanel.add(secondNumber);
        calcPanel.add(calculateButton);
        calcPanel.add(calcSolution);

        this.add(calcPanel);

        // End of setting up the components --------
    }

    public int getFirstNumber() {
        return Integer.parseInt(firstNumber.getText());
    }

    public int getSecondNumber() {
        return Integer.parseInt(secondNumber.getText());
    }

    public int getCalcSolution() {
        return Integer.parseInt(calcSolution.getText());
    }

    public void setCalcSolution(int solution) {
        calcSolution.setText(String.valueOf(solution));
    }

    // If the calculateButton is clicked execute a method
    // in the Controller named actionPerformed

    void addCalculateListener(ActionListener listenForCalcButton) {
        calculateButton.addActionListener(listenForCalcButton);
    }

    // Open a popup that contains the error message passed

    void displayErrorMessage(String errorMessage) {
        JOptionPane.showMessageDialog(this, errorMessage);
    }

}
