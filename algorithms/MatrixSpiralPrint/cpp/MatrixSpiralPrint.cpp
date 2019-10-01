#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/* 
    This program prints a 2D matrix in spiral form...

    Ex: {
            01, 02, 03, 04, 05,
            06, 07, 08, 09, 10,
            11, 12, 13, 14, 15,
            16, 17, 18, 19, 20
        }

        Output -> 1, 2, 3, 4, 5, 10, 15, 20, 19, 18, 17, 16, 11, 6, 7, 8, 9, 14, 13, 12
*/

int main()
{

    int arr[][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
        //{21, 22, 23, 24, 25}
    };

    int rowStart = 0, rowEnd = 4, colStart = 0, colEnd = 4;

    while (rowStart < rowEnd && colStart < colEnd)
    {

        // printing the next row from top
        for (int i = colStart; i <= colEnd; i++)
        {
            cout << "->" << arr[rowStart][i];
        }
        // removing the row from top as it is printed
        rowStart = rowStart + 1;

        // printing the next column in the right
        for (int i = rowStart; i <= rowEnd; i++)
        {
            cout << "->" << arr[i][colEnd];
        }
        // removing the column from right as it is printed
        colEnd = colEnd - 1;

        // printing the next row from bottom
        if (rowStart <= rowEnd)
        {
            for (int i = colEnd; i >= colStart; i--)
            {
                cout << "->" << arr[rowEnd][i];
            }
            // removing the row from bottom as it is printed
            rowEnd = rowEnd - 1;
        }

        // printing the column from start
        if (colStart <= colEnd)
        {
            for (int i = rowEnd; i >= rowStart; i--)
            {
                cout << "->" << arr[i][colStart];
            }
            // removing the column from start as it is printed
            colStart = colStart + 1;
        }
    }

    // cout << rowStart << rowEnd << colStart << colEnd;

    return 0;
}
