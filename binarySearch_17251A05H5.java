import java.util.Scanner;
class BinarySearch{
  public static void main(String args[]){
    
    //Scanning the elements of the array
    Scanner sc=new Scanner(System.in);
    System.out.println("enter no. of elements");
    int n=sc.nextInt();
    int[] a=new int[n];
    for(int i=0;i<n;i++) a[i]=sc.nextInt();
    
    System.out.println("enter the element to be searched");
    int key=sc.nextInt();
    
    //searching
    int l=0,h=a.length-1,m;
    while(l<=h){
        m=(l+h)/2;
        if(a[m]==key){System.out.println("element present at:"+m);return;}
        else if(a[m]>key){h=m-1;}
        else if(a[m]<key){l=m+1;}
    }
    System.out.println("element Not present");
  }
}
