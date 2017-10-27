/*Kadane's algorithm
 *
 *In dynamic problem maximum subarray problem is the task of finding the contiguous
 *subarray within a one-dimensional array of numbers which has the largest sum
 *
 */
public class kadane_algorithm {
	private static void getMaximumSubArray(int inputArray[]) {
		int sum = 0, max = 0;
		int startIndex = 0, endIndex = inputArray.length;
		for (int i = 0; i < inputArray.length; i++) {
			sum = sum + inputArray[i];
			if (sum <= 0) {
				sum = 0;
				startIndex = i + 1;
			} else if (max < sum) {
				max = sum;
				endIndex = i;
			}
		}
		System.out.println("Maximum contiguous sum is : " + max);
		System.out.println("Starting index  : " + startIndex);
		System.out.println("Ending index : " + endIndex);
	}

	public static void main(String[] args) {
		int inputArray[] = new int[] { 0, -1, 4, 5, -2, 7 };
		getMaximumSubArray(inputArray);
	}
}
