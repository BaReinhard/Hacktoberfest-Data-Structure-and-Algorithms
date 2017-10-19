import java.util.Scanner;

public class LinearSearch {

    public static void main(String args[])
    {
        int i;
        int desiredNumber;
        int numList[];

        Scanner in = new Scanner(System.in);
        numList = new int[] {1,2,3,4,5,6,7,8,9,10};

        System.out.println("Desired Number: ");
        desiredNumber = in.nextInt();

        for (i = 0; i < numList.length; i++)
        {
            if (numList[i] == desiredNumber)
            {
                System.out.println("Number found in the array");
                break;
            }
        }
        if (i == numList.length)
            System.out.println("Number not in the array");
    }
}


