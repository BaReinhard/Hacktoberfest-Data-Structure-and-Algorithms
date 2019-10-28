import java.util.ArrayList;

public class ArrayListOps {

	public static void main(String[] args) {

		int[] one = { 9, 9, 9, 9 };
		int[] two = { 9, 9 };

		System.out.println(sum(one, two));

	}

	public static ArrayList<Integer> intersection(int[] a1, int[] a2) {

		ArrayList<Integer> res = new ArrayList<>();

		int i = 0;
		int j = 0;

		while (i < a1.length && j < a2.length) {

			if (a1[i] == a2[j]) {
				res.add(a1[i]);
				i++;
				j++;
			} else if (a1[i] > a2[j]) {
				j++;
			} else {
				i++;
			}
		}
		return res;

	}

	public static ArrayList<Integer> sum(int[] a1, int[] a2) {

		ArrayList<Integer> res = new ArrayList<>();

		int i = a1.length - 1;
		int j = a2.length - 1;

		int carry = 0;

		while (i >= 0 || j >= 0) {

			int sum = carry;

			if (i >= 0) {
				sum += a1[i];
			}

			if (j >= 0) {
				sum += a2[j];
			}

			res.add(0, sum % 10);
			carry = sum / 10;

			i--;
			j--;
		}

		if (carry != 0) {
			res.add(0, carry);
		}
		return res;

	}

}
