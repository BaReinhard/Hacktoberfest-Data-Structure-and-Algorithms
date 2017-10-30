import java.util.Scanner;

public class KnapsackFrac {
	
	public static double MaxCost(int n,int[] wt,int[] val,int w) {
		double max = 0;
		double arr[] = new double[n];
		
		for(int i=0;i<n;i++) {
			arr[i] = (double)val[i]/(double)wt[i];
		}
		int mx;
		for(int i=0;i<n;i++) {
			mx = 0;
			for(int j=1;j<n;j++) {
				if(arr[mx] < arr[j]) {
					mx = j;
				}
			}
			arr[mx] = 0;
			if(w >= wt[mx]) {
				w = w - wt[mx];
				max = max + val[mx];
			}else {
				if(w!=0) {
					double frac = (double)w/(double)wt[mx];
					max = max + frac*val[mx];
					w=0;
				}
			}
			if(w == 0) {
				break;
			}			
		}
		
		return max;
	}

	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number weights");
		int n = sc.nextInt();
		System.out.println("Enter the weights");
		int wt[] = new int[n];
		for(int i=0;i<n;i++) {
			wt[i] = sc.nextInt();
		}
		System.out.println("Enter the values");
		int val[] = new int[n];
		for(int i=0;i<n;i++) {
			val[i] = sc.nextInt();
		}
		System.out.println("Enter the weight for cost maximizing");
		int w = sc.nextInt();
		
		double max = MaxCost(n,wt,val,w);
		System.out.println("Maximum value "+ max);
		sc.close();
	}
}
