import java.util.Scanner;

public class PowerComlexityLogN {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		System.out.println("Enter the base: ");
		int n = s.nextInt();
		System.out.println("Enter the exponent: ");
		int x = s.nextInt();
		System.out.println(power(x,n));
	}
	public static int power(int n,int x){
		if(n==0){
			return 1;
		}
		int pow;
		if(n%2==0){
			pow=power(n/2,x)*power(n/2,x);
	    }
		else{
			pow=x*power(n/2,x)*power(n/2,x);
		}
		return pow;
			
	}
}
