public class FiboSrch_ADT
{
	public static int fib_srch(int a[], int n, long key)
	{ 
   	 	int initpos=0, pos, k;
	        int fib[]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};
 
		if(n==-1)
			return -1;

    		k=0;
    		while(fib[k]<n) 
			k++;		// if n = 8, k = 13
   	
		while(k>0)
		{
    			pos=initpos+fib[--k]; // next position to be compared

			if(key == a[pos])	
				return pos;
			else
			if (key>a[pos])	// right side, then pos+1
    			{
        			initpos=pos+1;
        			k--;
    			}
    			else 
			     continue;	// element may be there towards left.. previous fib position will be considered
    		}
		
		return -1;		
	}
    	

	public static void main(String args[])
	{
    		int a[] = {1,3,15,36,45,67,78,91,-999};
		int key;

		key = Integer.parseInt(args[0]); // 

		int pos = fib_srch(a,8,key);

    		if(pos==-1)
			System.out.println("No such item found");
    		else
			System.out.println("Key found at Locaton :"+ pos);
	}
}
