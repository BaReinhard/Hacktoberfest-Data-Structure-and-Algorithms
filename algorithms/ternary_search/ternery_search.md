
*TERNARY SEARCH*

Like linear search and binary search, ternary search is a searching technique that is used to determine the position of 
a specific value in an array.
In binary search, the sorted array is divided into two parts while in ternary search,
it is divided into  parts and then you determine in which part the element exists.


The pseudo code is as follows-

```
int ternary_search(int l,int r, int x)
{
    if(r>=l)
    {
        int mid1 = l + (r-l)/3;
        int mid2 = r -  (r-l)/3;
        if(ar[mid1] == x)
            return mid1;
        if(ar[mid2] == x)
            return mid2;
        if(x<ar[mid1])
            return ternary_search(l,mid1-1,x);
        else if(x>ar[mid2])
            return ternary_search(mid2+1,r,x);
        else
            return ternary_search(mid1+1,mid2-1,x);

    }
    return -1;
}
```

*Which has more comparisons in the worst case? Binary Search or Ternary Search*

The following is recursive formula for counting comparisons in worst case of Binary Search.
```
   T(n) = T(n/2) + 2,  T(1) = 1
```
The following is recursive formula for counting comparisons in worst case of Ternary Search.
```
   T(n) = T(n/3) + 4, T(1) = 1
```
```
Time Complexity for Binary search = 2clog<sub>2</sub><sup>n</sup> + O(1)
Time Complexity for Ternary search = 4clog<sub>3</sub><sup>n</sup> + O(1)
```
Therefore, the comparison of Ternary and Binary Searches boils down the comparison of expressions 2log<sub>3</sub><sup>n</sup> and log<sub>2</sub><sup>n</sup>. The value of 2log<sub>3</sub><sup>n</sup> can be written as (2 / log<sub>2</sub><sup>3</sup>) * log<sub>2</sub><sup>n</sup> . Since the value of (2 / log<sub>2</sub><sup>3</sup>) is more than one, Ternary Search does more comparisons than Binary Search in worst case.


