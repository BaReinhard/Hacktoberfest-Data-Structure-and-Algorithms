public class Fibonacci{
	public static void main(String args[]){
		System.out.println("Test Value 10 = " + nth(10));
	}

	public static int nth(int i){
		return ( (int) ( (double) 
			( 1 / (double) Math.sqrt(5) ) * 
			Math.pow( ( (1 + Math.sqrt(5)) / 2 ), (i + 1))) );
	}
}
