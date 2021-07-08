import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.math.*;

public class Kadanes {
  public static void main(String[] args) {
    int[] arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    maxSubarray(arr);
  }

  private static void maxSubarray(int[] arr) {
    int startIdx = 0, endIdx = 0;
    int maxEndingHere = arr[startIdx];
    int maxSoFar = arr[startIdx];
    for(int i = 0; i < arr.length; i++) {
      int current = arr[i];
      if (current > (maxEndingHere + current)) startIdx = i;
      maxEndingHere = Math.max(current, maxEndingHere + current);
      if (maxEndingHere > maxSoFar) endIdx = i;
      maxSoFar = Math.max(maxSoFar, maxEndingHere);
    }
    String maxSubarrayItems = IntStream.range(startIdx, endIdx + 1).boxed().map(i -> arr[i]).map(Object::toString).collect(Collectors.joining(", "));
    System.out.println(String.format("Maximum subarray sum: %s", maxSoFar));
    System.out.println(String.format("Maximum subarray list: %s", maxSubarrayItems));
  }
}
