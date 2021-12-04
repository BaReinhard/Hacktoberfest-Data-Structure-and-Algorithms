program Heap_Sort;

type SArray = array of integer;
var Asize: integer;
var A: SArray;
var i: integer;

(** swap.
*
* Swaps two given values.
*
* @param a,b values to be swaped.
*)

procedure swap ( var a, b: integer );
var temp: integer;
begin
temp := a;
a := b;
b := temp;
end;

(** siftDown.
*
* Sifts downward to establish the heap property.
*
* @param A array.
* @param start heap root.
* @param end_ represents the limit of how far down the heap to sift.
*)

procedure siftDown ( var A: SArray; start, end_: integer );
var root, child: integer;
begin
root := start;

// While the root has at least one child
while ( root * 2 + 1 <= end_ ) do begin 
child := root * 2 + 1; // left child
// If the child has a sibling and
// the child's value is less than its sibling's
if ( child < end_ ) and ( A[child] < A[child + 1] ) then
child := child + 1; // point to the right child instead
if ( A[root] < A[child] ) then begin // out of max-heap order
swap ( A[root], A[child] );
root := child; // repeat to continue sifting down the child
end
else
break;
end;
end;

(** heapify.
*
* Builds a heap from the bottom up.
*
* The heapify function can be thought of as building a
* heap from the bottom up, successively sifting downward
* to establish the heap property.
*
* @param A array.
* @param count number of elements in A.
*)

procedure heapify ( var A: SArray; count: integer );
var start: integer;
begin
// start is assigned the index in A of the last parent node
start := (count - 1) div 2;

while ( start >= 0 ) do begin
// sift down the node at start index to the proper place,
// such that all nodes below the start index are in heap order
siftDown (A, start, count-1);
start := start - 1;
// after sifting down the root all nodes/elements are in heap order
end;
end;

(** heapSort.
*
* Sorts A=(A0, A1, ..., An) into nondecreasing order of keys.
* This algorithm has a worst case computational time of O(n log n).
* Not stable.
*
* Heapsort primarily competes with quicksort,
* another very efficient, general purpose, and
* nearly-in-place, comparison-based sort algorithm.
*
* Heapsort inserts the input list elements into a heap data structure.
* The largest value (in a max-heap) or the smallest value
* (in a min-heap) are extracted until none remain,
* the values being extracted in sorted order.
* The heap's invariant is preserved after each
* extraction, so the only cost is that of extraction.
*
* During extraction, the only space required is that needed to store
* the heap. In order to achieve constant space overhead, the heap
* is stored in the part of the input array that has not yet been sorted.
* (The structure of this heap is described at Binary heap:
* Heap implementation.)
*
* Heapsort uses two heap operations: insertion and root deletion.
* Each extraction places an element in the last empty location of
* the array. The remaining prefix of the array stores the
* unsorted elements.
*
* @param A array to be sorted.
* @param n number of elements to be sorted.
*)

procedure heapSort( var A: SArray; n: integer );
var end_: integer;
begin
// first place A in max-heap order
heapify ( A, n );

end_ := n - 1;
while ( end_ > 0 ) do begin
// swap the root (maximum value) of the heap
// with the last element of the heap
swap( A[end_], A[0]);
// decrease the size of the heap by one,
// so that the previous max value
// will stay in its proper placement
end_ := end_ - 1;
// put the heap back in max-heap order
siftDown (A, 0, end_);
end;
end;

begin
write ( 'Enter number of elements: ' );
read ( Asize );
// alocate an array from 0 to Asize-1
// the array index is always zero-based
SetLength ( A, Asize );
// generate the seed
randomize;
// fill A with random numbers in the range [0..99]
for i := 0 to Asize-1 do
A[i] := random (100);

// print original array
for i := 0 to Asize-1 do begin
write (A[i]); write (' ');
end;
writeln;

// sort
heapSort ( A, Asize );

// print sorted array
for i := 0 to Asize-1 do begin
write (A[i]); write (' ');
end;
writeln;
end.
