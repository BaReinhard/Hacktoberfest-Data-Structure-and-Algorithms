import java.util.*;
class Mobius
{
   
   public static  void main(String args[])
    {
        
        int res=0;
        Scanner in=new Scanner(System.in);
        System.out.println("Enter any no.:");
        int  N=in.nextInt();
       
    
      int p=0;
      boolean rep=false;
     
        int ar[]=new int[100];
        int i=2,k=0,j,f=0,x=N;
       for(i=2;i<x; )
       {
           while(x!=1)
           {
               if(x%i==0)
               {
                   ar[k++]=i;
                   x=x/i;
                }
                else
                i++;
            }
        }
                
          
        
      for(i=0;i<k-1;i++)
        {
            for(j=i+1;j<k;j++)
            {
                if(ar[i]==ar[j])
                f++;
            }
        }
        if(f>0)
        rep=true;
        else
        p=k;
      
        if(N==1)
        res=1;
        
        if(rep==true)
        res=0;
        else
        res=(int)(Math.pow(-1,p));
        System.out.println("Result:");
        System.out.println("M("+N+")="+res);
    }
}
    
        
      
    
    


            
            
                
            
        