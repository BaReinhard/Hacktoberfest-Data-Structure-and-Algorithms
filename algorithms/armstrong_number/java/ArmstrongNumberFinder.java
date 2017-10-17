import java.util.ArrayList;
import java.util.List;

/**
 * An Armstrong number of n digits is an integer such that the sum of the nth power of its digits is equal to the number itself.
 * <p/>
 * for eg. 153 = 1^3 + 5^3 + 3^3, 1634 = 1^4 + 6^4 + 3^4 + 4^4
 *
 * @author Shrikrushna Atkalikar
 */
public class ArmstrongNumberFinder {

    /**
     * Method to check if the given number is armstrong or not.
     *
     * @param num number to check if its armstrong
     * @return true if number is armstrong number and false is not.
     */
    public static boolean isArmstrongNumber(int num) {
        int temp = num;
        int total = 0;
        int power = String.valueOf(num).length();
        while (temp > 0) {
            int r = temp % 10;
            total += Math.pow(r, power);
            temp = temp / 10;
        }
        return total == num;
    }

    /**
     * Method to find armstrong numbers in a given range.
     *
     * @param lower lower bound of the range
     * @param upper upper bound of the range
     * @return list of armstrong numbers in a given range.
     */
    public static List<Integer> armstrongNumbersInRange(int lower, int upper) {
        checkArgument(lower, "lower");
        checkArgument(upper, "upper");
        validateBounds(lower, upper);
        List<Integer> armstrongNums = new ArrayList<>();
        for (int i = lower; i <= upper; i++) {
            if (isArmstrongNumber(i)) {
                armstrongNums.add(i);
            }
        }
        return armstrongNums;
    }

    private static void validateBounds(int lower, int upper) {
        if (lower > upper) {
            throw new IllegalStateException("Lower bound can not be greater than upper bound.");
        }
    }

    private static void checkArgument(int bound, String type) {
        if (bound < 0) {
            throw new IllegalArgumentException(type + " can not be less than zero.");
        }
    }
}
