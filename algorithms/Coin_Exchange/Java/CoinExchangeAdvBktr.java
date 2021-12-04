import java.util.Scanner;

public class CoinExchangeAdvBktr {
	
	public static String coinChangeAdv(int t,int n,int ar[]) {
		int arr[][] = new int[t+1][n+1];
		
		for(int i=0;i<=n;i++) {
			arr[0][i] = 0;
		}
		
		for(int i=0;i<=t;i++) {
			arr[i][0] = 0;
		}
		
		
		for(int j=1;j<=n;j++) {
			for(int i=1;i<=t;i++) {
				arr[i][j] = arr[i][j-1];
				
				if(i>=ar[j]) {
					if(arr[i][j] == 0) {
						if(i % ar[j]==0) {
							arr[i][j] = 1 + arr[(i-ar[j])][j];
							//System.out.println(arr[i][j]+" "+arr[(i-ar[j])][j]);
						}
					}else {
						if((arr[(i-ar[j])][j] == 0)&&(i-ar[j]==0)) {
							if(arr[i][j] > 1 + arr[(i-ar[j])][j]) {
								arr[i][j] = 1 + arr[(i-ar[j])][j];
							}
						}else {
							if(arr[(i-ar[j])][j] != 0) {
								if(arr[i][j] > 1 + arr[(i-ar[j])][j]) {
									arr[i][j] = 1 + arr[(i-ar[j])][j];
								}
							}
						}
						
					}
					//System.out.println(arr[i][j]+" "+arr[(i-ar[j])][j]);
				}				
			}
		}
		
		String str = "";
		
		int i = t;
		int j = n;
		while((i!=0)&&(j!=0)) {
			if(arr[i][j] != 0) {
				if(arr[i][j] != arr[i][j-1]) {
					i = i-ar[j];
					str = str + ar[j] + " ";
				}else {
					j = j-1;
				}
			}else {
				str = "Not possible with these coins";
				i=0;
			}
		}
		
		return str;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number of coin denomination");
		int n = sc.nextInt();
		
		int ar[] = new int[n+1];
		System.out.println("Enter value of coin");
		for(int i=1;i<=n;i++) {
			ar[i] = sc.nextInt();
		}
		System.out.println("Enter value");
		int t = sc.nextInt();		
		
		String str = coinChangeAdv(t,n,ar);
		System.out.println(str);
				
		sc.close();
	}

}
