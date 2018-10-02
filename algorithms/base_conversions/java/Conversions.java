import java.util.Scanner;

public class Conversions {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int bin = s.nextInt();
		System.out.println(BinToDec(bin));
		int deci = s.nextInt();
		System.out.println(DecToBin(deci));
		int number = s.nextInt();
		int sb = s.nextInt();
		System.out.println(AnyToDec(number, sb));
		int number2 = s.nextInt();
		int db = s.nextInt();
		System.out.println(DecToAny(number2, db));
		int number3 = s.nextInt();
		int db1 = s.nextInt();
		int sb1 = s.nextInt();
		System.out.println(AnyToAny(number3, db1, sb1));
	}

	public static int BinToDec(int bin) {
		int deci = 0, x = 0, pow = 1, rem;
		while (bin != 0) {
			pow = 1;
			for (int i = 1; i <= x; i++)
				pow = 2 * pow;
			rem = bin % 10;
			deci = deci + rem * pow;
			bin = bin / 10;
			x++;

		}

		return deci;
	}

	public static int DecToBin(int decimal) {
		int binary, rev = 0, pow = 1;
		while (decimal != 0) {
			binary = decimal % 2;
			rev = rev + binary * pow;
			pow = pow * 10;
			decimal = decimal / 2;
		}
		return rev;
	}
	
	

	public static int AnyToDec(int number, int sb) {

		int deci = 0, x = 0, pow = 1, rem;
		while (number != 0) {
			pow = 1;
			for (int i = 1; i <= x; i++)
				pow = sb * pow;
			rem = number % 10;
			deci = deci + rem * pow;
			number = number / 10;
			x++;

		}

		return deci;

	}

	public static int DecToAny(int number, int db) {
		int binary, rev = 0, pow = 1;
		while (number != 0) {
			binary = number % db;
			rev = rev + binary * pow;
			pow = pow * 10;
			number = number / db;
		}
		return rev;
	}

	public static int AnyToAny(int number, int sb, int db) {
		int dec = AnyToDec(number, sb);
		int req = DecToAny(dec, db);
		return req;
	}
}
