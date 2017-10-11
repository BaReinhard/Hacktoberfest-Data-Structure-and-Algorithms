## ELI5
**Binary Serch** is a way of searching for a thing in a list of things. The list must be sorted, that is, it must be in order of some comparable value or the it won't work. First, we go to the middle of the list and see if the item value equals to the value we want to find. Then, if our value is less/greater than the item in the middle, we work on a new list (which starts from the middle and all the way to the bottom or top) and everything on the bottom or top side. We keep doing this until we find the value we were looking for or if were fluctuating between two elements.

## Pros
* It takes too much less time than a reqular sequential search

## Cons
* The list must be sorted

## Technical Explanation

If we have the list

`a = [45,64,68,46,70,6,46,4,6,48]`

And we want to find an element if it exists in the list or not

The naive solution is to go in the list element by element, ask if this is the element I'm looking for or not.

The worest case is that the element is not in the list, or at the end of it,

then the time Complexity it takes to end the search process is O(n);

We can to do better.

Here comes the **Binary Search**,

Pseudocode for Binary Searching:

Given an array A of n elements with values or records A0, A1, ..., An−1, sorted such that A0 ≤ A1 ≤ ... ≤ An−1, and target value T, the following subroutine uses binary search to find the index of T in A.[7]
1. Set L to 0 and R to n − 1.
2. If L > R, the search terminates as unsuccessful.
3. Set m (the position of the middle element) to the floor (the largest previous integer) of (L + R) / 2.
4. If Am < T, set L to m + 1 and go to step 2.
5. If Am > T, set R to m − 1 and go to step 2.
6. Now Am = T, the search is done; return m.

## Pros
* The Time Complexity is O(log(n))
* Binary search adds a small amount of complexity for large performance gains.
* Simple to write.
* One of the fastest way to find elements in a list.

## Cons
* The list must be sorted, which is,
* The complexity can increase when the collection is not stored in a simple structure, such as a list.
* The list has to be sorted.
* Doesn't help in reducing the time much and adds complexity for small arrays.
