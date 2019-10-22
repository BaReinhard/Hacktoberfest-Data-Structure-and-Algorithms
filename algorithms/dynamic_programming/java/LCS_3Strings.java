// Java program to find LCS of three strings 
public class LCS_3Strings { 
	
	/* Returns length of LCS for X[0..m-1], Y[0..n-1] 
	and Z[0..o-1] */
	static int lcsOf3(String X, String Y, String Z, int m, 
								int n, int o) 
	{ 
		int[][][] L = new int[m+1][n+1][o+1]; 
	
		/* Following steps build L[m+1][n+1][o+1] in 
		bottom up fashion. Note that L[i][j][k] 
		contains length of LCS of X[0..i-1] and 
		Y[0..j-1] and Z[0.....k-1]*/
		for (int i=0; i<=m; i++) 
		{ 
			for (int j=0; j<=n; j++) 
			{ 
				for (int k=0; k<=o; k++) 
				{ 
					if (i == 0 || j == 0||k==0) 
						L[i][j][k] = 0; 
	
					else if (X.charAt(i - 1) == Y.charAt(j - 1) 
								&& X.charAt(i - 1)==Z.charAt(k - 1)) 
						L[i][j][k] = L[i-1][j-1][k-1] + 1; 
	
					else
						L[i][j][k] = Math.max(Math.max(L[i-1][j][k], 
											L[i][j-1][k]), 
										L[i][j][k-1]); 
				} 
			} 
		} 
	
		/* L[m][n][o] contains length of LCS for 
		X[0..n-1] and Y[0..m-1] and Z[0..o-1]*/
		return L[m][n][o]; 
	} 
	
	/* Driver program to test above function */
	public static void main(String args[]) 
	{ 
		String X = "AGGT12"; 
		String Y = "12TXAYB"; 
		String Z = "12XBA"; 
	
		int m = X.length(); 
		int n = Y.length(); 
		int o = Z.length(); 
	
		System.out.println("Length of LCS is " + 
								lcsOf3(X, Y,Z, m, n, o)); 
	
	} 
} 
