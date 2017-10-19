package main;

public class Main {

	static void sort(int[] arr) {
		for (int i : arr) {
			Runnable r = new Runnable() {
				@Override
				public void run() {
					try {
						Thread.sleep(i * 1000);
						System.out.println(i);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
			};

			Thread t = new Thread(r);
			t.start();
		}

	}

	public static void main(String[] args) {
		int[] arr = { 50, 40, 39, 21, 27, 7 };
		sort(arr);
	}
}