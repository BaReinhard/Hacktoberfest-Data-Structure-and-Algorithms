import javax.lang.model.element.Element;

public class OptimalBst {
	
	static int[] elements = {5,6,8,20};
	
	static int[] access = {4,2,6,3} ;
	
	public static void main(String[] args) {
		
		int len = elements.length ;
		
		int[][] solution = new int[len][len] ;
		
		for (int i = 0; i < solution.length; i++) {
			for (int j = 0; j < solution.length; j++) {
				solution[i][j] = 0 ;
			}
		}
		
		for (int i = 0; i < solution.length; i++) {
			for (int j = 0; j < solution.length; j++) {
				if(i == j) {
					solution[i][j] = access[i] ;
				}
			}
		}
		
		for (int i = 0 ; i < solution.length-1 ; i++) {
			
			for (int j = 0; j < solution.length - 1; j++) {
				
				for (int k = i+j+1 ; k < solution.length ; k++) {
					
					if(k == i+j+1) {
						solution[j][k] = findMinimum(solution , j , k);
					}
				}
			}
		}
		
		 for (int i = 0; i < solution.length; i++) {
			for (int j = 0; j < solution.length; j++) {
				System.out.print(solution[i][j] + " ");
			}
			System.out.println();
		} 
		
		System.out.println("\nCost of Optimal Binary Search Tree : " + solution[0][solution.length - 1]);
		
	}
	
	public static int findMinimum(int[][] array , int i , int j){
		
		int min = Integer.MAX_VALUE ;
		int baseSum = 0 ;
		
		for (int k = i ; k <= j ; k++) {
			baseSum += access[k] ;			
		}
		
		for (int k = i ; k <= j ; k++) {
			
			int temp = 0 ;
			
			if(k == i) {
				temp = baseSum +  array[k+1][j] ;
			}else if(k == j) {
				temp = baseSum +  array[i][j-1] ;
			}else{
				temp = baseSum +  array[i][k-1] + +  array[k+1][j] ;
			}
			
			if(temp <= min) {
				min = temp ;
			}
		}
		
		return min ;
		
	}
	

}
