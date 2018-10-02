import java.util.*;
import java.lang.*;
import java.io.*;
class SegmentTree
{
    int st[];
    Segment(int []arr, int n)
    {
        int x = (int) Math.ceil((Math.log(n)/Math.log(2)));
        int max_size = 2 *(int) (Math.pow(2,x) - 1);
        st = new int[max_size];
        
        constSegmentUtil(arr,0,n-1,0);
    }
    
    int constSegmentUtil(int []arr, int ss,int se,int si)
    {
        if(ss == se)
        {
          st[si] = arr[ss];
          return arr[ss];
        }
        int mid = getMid(ss,se);
        st[si] = max(constSegmentUtil(arr,ss,mid,2*si+1),constSegmentUtil(arr,mid+1,se,2*si+2));
        return st[si];
    }
    
    int getMid(int s,int e)
    {
		  return s + (e - s)/2;
    }
    
    int max(int a,int b)
    {
      if(a > b)
      {
        return a;
      }
      else{
        return b;
      }
    }
    
    void print(){
        for (int i=0;i<st.length;i++ )
        {
            System.out.print(st[i]);
        }
    }
    
    int getMaxUtil(int ss,int se,int qs,int qe,int si)
    {
        if(qs<=ss && qe>=se)
        {
            return st[si];
        }
        
        if(se<qs || ss>qe)
        {
            return 0;
        }
        
        int mid = getMid(ss,se);
        
        return max(getMaxUtil(ss,mid,qs,qe,2*si+1),getMaxUtil(mid+1,se,qs,qe,2*si+2));
    }
    
    
    int getMax(int n,int qs,int qe){
        
        if(qs > qe || qs < 0 || qe > n-1){
            return -1;
        }
        
        return getMaxUtil(0,n-1,qs,qe,0);
    }
    
	public static void main (String[] args) throws java.lang.Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());//for testcase
		String []temp = br.readLine().split(" ");//taking array as string
		int []arr = new int[t];
		for(int i=0;i<t;i++) //to convert array of string to array of integers
		{
		    arr[i] = Integer.parseInt(temp[i]); 
		}
		Segment tree = new Segment(arr,arr.length);
		//tree.print();
		int q = Integer.parseInt(br.readLine()); // no of queries
		while (q--!=0)
		{
		    String []temp1 = br.readLine().split(" ");
		    int s = Integer.parseInt(temp1[0]); //q1
		    int e = Integer.parseInt(temp1[1]); //q2
		 
		    System.out.println(tree.getMax(arr.length,s-1,e-1));   // maximum in range [q1,q2]
		    //System.out.println(getMax(arr,n,s,e));
		}
	}
}

