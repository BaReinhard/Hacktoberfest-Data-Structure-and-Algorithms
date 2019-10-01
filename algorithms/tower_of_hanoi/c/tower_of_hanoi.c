#include <stdio.h>

//Recursive funtion to solve tower of hanoi problem
void tower_of_hanoi(int n, char source, char destination, char auxillary)
{

    if(n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", source, destination);
        return;
    }

    tower_of_hanoi(n-1, source, auxillary, destination);
    printf("\n Move disk %d from rod %c to rod %c", n, source, destination);
    tower_of_hanoi(n-1,auxillary, destination, source);

}


int main()
{

    int n;  // number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    //A B and C are names of rods
    tower_of_hanoi(n,'A', 'C', 'B');

    return 0;

}
