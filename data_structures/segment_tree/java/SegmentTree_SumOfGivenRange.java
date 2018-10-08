/* Java program to solve the following problem using Segment Trees
 * We have an array arr[0 . . . n-1]. We should be able to
 * 1) Find the sum of elements from index l to r where 0 <= l <= r <= n-1
 * 2) Change value of a specified element of the array to a new value x. We need to do arr[i] = x where 0 <= i <= n-1.
 */
import java.util.*;
public class SegmentTree_SumOfGivenRange{
	private int[] arr;// The array on which queries are made
	int n;            // Number of elements
	private int[] st; // The array that stores segment tree nodes

	/* Constructor to construct segment tree from given array. This constructor  allocates memory for segment tree */
	public SegmentTree_SumOfGivenRange(int[] arr){
		this.arr=arr;
		n=arr.length;
		int h=(int)Math.ceil(Math.log(n)/Math.log(2));    //height of the segment tree will be log(n)
		st=new int[2*(int)Math.pow(2,h)-1];		  //Maximum size of segment tree is allocated

	}

	/* A function that constructs the segment tree for array */
	public int[] constructTree(){
		constructUtil(0,n-1,0); //constructs tree for array[0...n-1]
		return st;
	}

	/* A recursive function that constructs Segment Tree for array[ss..se].
         * si is index of current node in segment tree st */
	private int constructUtil(int l,int r,int si){
		// If there is one element in array, store it in current node of segment tree and return
		if(l==r){
			st[si]=arr[l];
			return arr[l];
		}
		// If there are more than one elements, then recur for left and right subtrees and store the sum of values in this node
		int mid=(l+r)/2;
		st[si]=constructUtil(l,mid,2*si+1) + constructUtil(mid+1,r,2*si+2);
		return st[si];
	}

	/*Return sum of elements in range from index qs (quey start) to qe (query end).  It mainly uses getSumUtil()*/
	public int getSum(int qs,int qe){
		if (qs < 0 || qe >= n || qs > qe) {
            		System.out.println("Invalid Input");
            		return -1;
        	}
		return getSumUtil(0,n-1,qs,qe,0);
	}

	/* A recursive function to get the sum of values in given range of the array.  The following are parameters for this function.
         * si --> Index of current node in the segment tree. Initially 0 is passed as root is always at index 0
         * l & r --> Starting and ending indexes of the segment represented by current node, i.e., st[si]
         * qs & qe --> Starting and ending indexes of query range */
	private int getSumUtil(int l,int r, int qs,int qe,int si){
		// If segment of this node is a part of given range, then return the sum of the segment		
		if(qs<=l && r<=qe){
			return st[si];
		}

		// If segment of this node is outside the given range
		if(r<qs || l>qe)
			return 0;

		// If a part of this segment overlaps with the given range
		int mid=(l+r)/2;
		return getSumUtil(l,mid,qs,qe,2*si+1)+ getSumUtil(mid+1,r,qs,qe,2*si+2);
	}

	/* The function to update a value in input array and segment tree
   	 * It uses updateValueUtil() to update the value in segment tree */
    	public void updateValue(int i, int new_val){
		if (i < 0 || i >= n) {                // Check for erroneous input index  
		    System.out.println("Invalid Input");
		    return;
		}
		int diff = new_val - arr[i];             // Get the difference between new value and old value
		arr[i] = new_val;                        // Update the value in array
		updateValueUtil(0, n - 1, i, diff, 0);   // Update the values of nodes in segment tree
		//Print updated array
		System.out.print("Updated array: ");
		for(int j=0;j<n;j++)
			System.out.print(arr[j]+" ");
		System.out.println();
    	}

	/* A recursive function to update the nodes which have the given index in their range. The following are parameters
         * si, l and r are same as getSumUtil()
         * i --> index of the element to be updated. This index is in input array.
         * diff --> Value to be added to all nodes which have i in range */
    	private void updateValueUtil(int l, int r, int i, int diff, int si)
    	{
		if (i < l || i > r)  // Base Case: If the input index lies outside the range of this segment
		    return;
	 
		// If the input index is in range of this node, then update the value of the node and its children
		st[si] = st[si] + diff;
		if (r != l) {
		    int mid = (l+r)/2;
		    updateValueUtil(l, mid, i, diff, 2 * si + 1);
		    updateValueUtil(mid + 1, r, i, diff, 2 * si + 2);
		}
        }

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the size of the array");
		int n = in.nextInt();
		int[] arr = new int[n]; 
		System.out.println("Enter the array values");
		for(int i=0;i<n;i++){
			arr[i] = in.nextInt();		
		}
		SegmentTree_SumOfGivenRange tree=new SegmentTree_SumOfGivenRange(arr);
		int[] st=tree.constructTree();   // Build segment tree from given array
		System.out.println("Enter the 2 indexes of range for which sum is to be found:");
		int l = in.nextInt();
		int r = in.nextInt();
		System.out.println("Sum of values in given range = "+tree.getSum(l,r));  // Print sum of values in array from index l to r
		System.out.println("Enter the index to be updated and value with which it is to be updated:");
		int i = in.nextInt();
		int value = in.nextInt();
		tree.updateValue(i, value); // Update: set arr[i] = value and update corresponding segment tree nodes
		System.out.println("Updated sum of values in given range = "+tree.getSum(l,r));  
        	
	}

}
