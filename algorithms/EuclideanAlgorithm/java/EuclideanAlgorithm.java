public class EuclideanAlgorithm{

	public static void main(String[] args){
		System.out.println(gcd(Integer.parseInt(args[0]),Integer.parseInt(args[1])));
	}

	public static int gcd(int a, int b){
		if(b==0){
			return a;
		}
		else{
			return gcd(b,a%b);
		}
	}
	
}
