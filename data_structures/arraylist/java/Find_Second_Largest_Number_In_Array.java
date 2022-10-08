import java.util.Arrays;

/**
 * To find second highest number form the array :
 * example :
 * arr = { 23,45,65,4,6,7}
 * output : 45
 * */
public class SecondHighestNumberInArray {
    //functin
    public  static  void SecondLargestNum(int arr[]){
        int size = arr.length;
        if(size<2){
            System.out.println("Invalid input ");
            return;
        }
        Arrays.sort(arr);
        System.out.println(arr[size-2]);
        for(int i= size-2; i>=0; i--){
            if(arr[i]!=arr[size-1]) {
                System.out.println(arr[i]);
                return;
            }

        }
        System.out.println("There are no largest number ");
    }
    public static void main(String[] args) {
        int arr[] = {4,4,4,4,4,4,4,4,4};
        //object of class
        SecondHighestNumberInArray secondHigh = new SecondHighestNumberInArray();
        secondHigh.SecondLargestNum(arr);

    }
}

//output : there are no largest numebr 
