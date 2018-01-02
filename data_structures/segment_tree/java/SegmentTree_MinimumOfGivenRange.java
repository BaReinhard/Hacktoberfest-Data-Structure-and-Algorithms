/* Java program to solve the following problem using Segment Trees
 * We have an array arr[0 . . . n-1].
 * We should be able to efficiently find the minimum value from index qs (query start) to qe (query end) where 0 <= qs <= qe <= n-1
 */
import java.util.*;
public class SegmentTree_MinimumOfGivenRange{
	private int[] arr;// The array on which queries are made
	int n;            // Number of elements
	private int[] st; // The array that stores segment tree nodes

	/* Constructor to construct segment tree from given array. This constructor  allocates memory for segment tree */
	public SegmentTree_MinimumOfGivenRange(int[] arr){
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

	/* Return minimum of elements in range from index qs (query start) to qe (query end).  It mainly uses getMinUtil()*/
	public int getMin(int qs,int qe){
		// Check for erroneous input values
		if (qs < 0 || qe >= n || qs > qe) {
		    System.out.println("Invalid Input");
		    return -1;
		}
	 
		return getMinUtil(0, n - 1, qs, qe, 0);
	}

	/* A recursive function to get the minimum value in a given range of array indexes. The following are parameters for this function.
         * si --> Index of current node in the segment tree. Initially 0 is passed as root is always at index 0
         * l & r --> Starting and ending indexes of the segment represented by current node, i.e., st[si]
         * qs & qe --> Starting and ending indexes of query range */
	private int getMinUtil(int l,int r, int qs,int qe,int si){
		// return the min of the segment
		if (qs <= l && qe >= r)
		    return st[si];
	 
		// If segment of this node is outside the given range
		if (r < qs || l > qe)
		    return Integer.MAX_VALUE;
	 
		// If a part of this segment overlaps with the given range
		int mid = (l+r)/2;
		return Math.min(getMinUtil(l, mid, qs, qe, 2 * si + 1),getMinUtil(mid + 1, r, qs, qe, 2 * si + 2));
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
		SegmentTree_MinimumOfGivenRange tree=new SegmentTree_MinimumOfGivenRange(arr);
		int[] st=tree.constructTree();   // Build segment tree from given array
		System.out.println("Enter the 2 indexes of range for which minimum is to be found:");
		int l = in.nextInt();
		int r = in.nextInt();
		System.out.println("Minimum of values in given range = "+tree.getMin(l,r));// Print minimum of values in array from index l to r
	}

}
