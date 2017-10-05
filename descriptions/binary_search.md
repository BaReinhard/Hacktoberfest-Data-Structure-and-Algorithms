## ELI5
the binary search algorithm is a search algorithm that searches an element in a list of elements, and the list must be sorted

## Pros
* it takes too much less time than a reqular sequential search

## Cons
* the list must be sorted

## Technical Explanation

if we have the list

list = [45,64,68,46,70,6,46,4,6,48]

and we want to find an element if it exists in the list or not

the naive solution is to go in the list element by element, ask if this is the element i'm looking for or not

the worest case is that the element is not in the list, or at the end of it,

then the time Complexity it takes to end the search process is O(n);

we need to do better

here comes the binary search

which finds the result in Time Complexity of O(log(n));

the first step is to sort the list,

and then..

while (the list is not empty and the first index is not > the last index):
  start at th mid of the list:
    if this is what tou want:
       we are done
    else if this is less than what we want:
       consider the list is only the "right section of the list" and repeat
    else if this is greater than what we want:
       consider the list is only the "left section of the list" and repeat

binary search works as splitting the list into sublists and follow the element you are looking for

## Pros
* the Time Complexity is O(log(n))

## Cons
* the list must be sorted, which is,

if the list is sorted:
  use binary search whether you will use it continuously or only one time
if it's not sorted:
  if you are using it continuously:
    sort it and use binary search
  else
    use sequential search



  
