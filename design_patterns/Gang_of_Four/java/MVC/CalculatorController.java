package MVC;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CalculatorController {

    // The Controller coordinates interactions
    // between the View and Model

    private CalculatorView view;
    private CalculatorModel model;

    public CalculatorController(CalculatorView view, CalculatorModel model) {
        this.view = view;
        this.model = model;

        // Tell the View that when ever the calculate button
        // is clicked to execute the actionPerformed method
        // in the CalculateListener inner class

        this.view.addCalculateListener(new CalculateListener());
    }

    class CalculateListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent ae) {
            int firstNumber, secondNumber, solution;

            // Surround interactions with the view with
            // a try block in case numbers weren't
            // properly entered

            try {
                firstNumber = view.getFirstNumber();
                secondNumber = view.getSecondNumber();

                model.addTwoNumbers(firstNumber, secondNumber);

                solution = model.getCalculationValue();
                view.setCalcSolution(solution);

            } catch (NumberFormatException e) {
                e.printStackTrace();
                view.displayErrorMessage("You Need to Enter 2 Integers");
            }
        }
    }
}
