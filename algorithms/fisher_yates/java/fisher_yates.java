import java.util.Random;

public class fisher_yates{

	public static void main(String[] args) {
			int[] arr = {1,2,3,4,5,6,7,8,9};

			System.out.println("Array before shuffling:");
			for(int i: arr) System.out.print(i + ", ");

			System.out.println("\n\nShuffling...");
			arr = shuffle(arr);

			System.out.println("\nArray after shuffling:");
			for(int i: arr) System.out.print(i + ", ");
	}


	
	public static int[] shuffle(int[] arr) {
		int switchIndex = arr.length - 1;
		int roll; 
		int temp;

		Random rng = new Random();

		while(switchIndex != 0) {
			roll = rng.nextInt(switchIndex);
			temp = arr[roll];
			arr[roll] = arr[switchIndex];
			arr[switchIndex] = temp;
			switchIndex--;
		}

		return arr;
	}
}
