import java.util.*;
class CircularShift
{
   public static void main(String args[])
   {
       int i,j;
       Scanner in=new Scanner(System.in);
       System.out.println("Enter the no. of elements:");
       int n=in.nextInt();
       String ar[]=new String[n];
       String t="";
       System.out.println("Enter the elements:");
       for(i=0;i<n;i++)
       ar[i]=in.next()+in.nextLine();
       
       for(i=0;i<n;i++)
       System.out.print(ar[i]+" ");
       System.out.println();
       for(i=0;i<n;i++)
       {
           t=ar[n-1];
          for(j=n-1;j>=1;j--)
          {
             ar[j]=ar[j-1];
            }
            ar[0]=t;
            
         for(j=0;j<n;j++)
         System.out.print(ar[j]+" ");
         System.out.println();
        }
    }
}
/* OUTPUT
 * Enter the no. of elements:
4
Enter the elements:
a
b
c
d
a b c d 
d a b c 
c d a b 
b c d a 
a b c d
 */

              
              
           
           
       
       