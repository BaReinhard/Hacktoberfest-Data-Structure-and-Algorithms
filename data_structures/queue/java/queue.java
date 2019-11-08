import java.util.Arrays;
import java.util.Scanner;

class Queue {

	private String[] array;
	private int tail;
	private static final String FULL = "full";
	private static final String EMPTY = "empty";

	public Queue(int size) {
			this.array = new String[size];
			this.tail = -1;
		}

	public void add(String value) {
		if (!isFull()) {
			tail++;
			array[tail] = value;
		} else {
			System.out.println(FULL);
		}
	}

	public void remove() {
		if (!isEmpty()) {
			shift();
			tail--;
		} else {
			System.out.println(EMPTY);
		}
	}

	private void shift() {
		for (int i = 1; i <= tail; i++) {
			this.array[i - 1] = this.array[i];
		}

	}

	public String print() {
		if (isEmpty()) {
			return EMPTY;
		}
		String saida = "";
		for (int i = 0; i <= tail; i++) {
			saida += array[i] + " ";
		}
		return saida.trim();

	}

	public boolean isEmpty() {
		return (tail == -1);
	}

	public boolean isFull() {
		return (tail == array.length - 1);
    }
    
    private String element() {
		if (isEmpty())
			return EMPTY;
		return this.array[0];
	}

}