import java.util.Arrays;
import java.util.List;
import java.util.Collections;

public class BogoSort {
	
	public static List<Integer> bogoSort(List<Integer> nums) {
		if (isSorted(nums)) {
			return nums;
		}
		
		for (;;) {
			Collections.shuffle(nums);
			
			if (isSorted(nums)) {
				break;
			}
		}
		
		return nums;
	}
	
	public static boolean isSorted(List<Integer> nums) {
		Integer[] x = nums.toArray(new Integer[nums.size()]);
		for (int i = 0; i < x.length - 1; i++) {
			if (x[i] > x[i + 1]) {
				return false;
			}
		}
		
		return true;
	}
}