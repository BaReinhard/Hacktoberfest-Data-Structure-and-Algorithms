public class Kadane {

	public static void main(String[] args) {
		new Kadane().KadaneAlgo();
	}

	public void KadaneAlgo() {
		
		int[] arr = {-2, 3, 2, -1};
		int local_max = arr[0], global_max = arr[0];
		
		for (int i = 1; i< arr.length; i++) {
			local_max = Max(arr[i], arr[i] + local_max);
			
			if (local_max > global_max) {
				global_max = local_max;
			}
		}
		
		System.out.println("Maximum sub-array sum: " + global_max);
		
	}
	
	public int Max(int a, int b) {
		if (a < b) return b;
		else return a;
	}
	
}
