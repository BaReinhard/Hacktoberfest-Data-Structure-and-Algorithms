package MVC;

public class Execute {

    public static void main(String[] args) {

        CalculatorModel model = new CalculatorModel();
        CalculatorView view = new CalculatorView();
        CalculatorController controller = new CalculatorController(view, model);

        view.setVisible(true);
    }
}
