import java.util.Scanner;
class matrix_operation_2D_array{
    public static void print(int a[][], int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(a[i][j]+"  ");
            }
            System.out.print("\n");
        }
    }
    public static void addition(int a[][], int n1, int m1, int b[][], int n2, int m2){
        int c[][] = new int[n1][m2];
        try{
            
            for (int i = 0; i < n1; i++) {
                for (int j = 0; j < m1; j++) {
                    c[i][j] = a[i][j] + b[i][j];
                }
            }
            System.out.println("Addition successful! \nC = A + B = ");
            print(c, n1, m1);
        }
        catch(Exception e){
            System.out.println("Cannot add matrix A and B : Size is different");
        }

        
    }

    public static void multiplication(int a[][], int n1, int m1, int b[][], int n2, int m2) {
        int d[][] = new int[n1][m2];
        try{
            for (int i = 0; i < n1; i++) {
                for (int j = 0; j < m2; j++) {
                    for(int k = 0; k < n2; k++){
                        d[i][j] += a[i][k] * b[k][j];
                    }
                }
            }
            System.out.println("multiplication successful! \nC = A * B = ");
            print(d, n1, m2);
        }
        catch(Exception e){
            System.out.println("Cannot multiply matrix A and B : Size is inapriopriate");
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of rows:");
        int n1 = sc.nextInt();
        System.out.println("Enter number of columns:");
        int m1 = sc.nextInt();
        int a[][] = new int[n1][m1];
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < m1; j++) {
                System.out.print("Enter element at ["+ (i+1) + "," + (j+1) + "] position:");
                a[i][j] = sc.nextInt();
            }
        }
        System.out.println("Matrix A = ");
        print(a, n1, m1);

        System.out.println("Enter number of rows of 2nd matrix:");
        int n2 = sc.nextInt();
        System.out.println("Enter number of columns of 2nd matrix:");
        int m2 = sc.nextInt();
        int b[][] = new int[n2][m2];
        for (int i = 0; i < n2; i++) {
            for (int j = 0; j < m2; j++) {
                System.out.print("Enter element at ["+ (i+1) + "," + (j+1) + "] position:");
                b[i][j] = sc.nextInt();
            }
        }

        sc.close();
        
        System.out.println("Matrix B = ");
        print(b, n2, m2);

        addition(a, n1, m1, b, n2, m2);
        multiplication(a, n1, m1, b, n2, m2);


    }
}
