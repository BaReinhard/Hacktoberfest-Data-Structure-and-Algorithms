import java.util.Arrays;
import java.util.Scanner;

/* 
 * Longest Increasing Subsequence will find the length of number of elements which are in sorted order.
 * The subsequence will be the largest of all the possibilities and does not contain any repeated element.  
 * For example:
 * Consider the following sequence: 10 1 2 5 6 2 4 8 7 5 of 10 characters
 * The largest possible subsequence would be 1 2 5 6 8 with length 5
 * Complexity- O(nlgn)
 */

public class LongestIncreasingSubsequence {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of elements ");
		int n = sc.nextInt();
		System.out.println("Enter the elements separated by space");
		int arr[] = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		sc.close();
		int dp[] = new int[n];
		Arrays.fill(dp, Integer.MAX_VALUE);
		for (int i = 0; i < n; i++) {
			int idx = Arrays.binarySearch(dp, arr[i]);
			if (idx < 0) {
				idx = -1 * (idx + 1);
			}
			dp[idx] = arr[i];
		}
		int len = 0;
		for (int i = 0; i < n; i++) {
			if (dp[i] == Integer.MAX_VALUE)
				break;
			len++;
		}
		System.out.printf("The length of LIS is: %d",len);
	}
}