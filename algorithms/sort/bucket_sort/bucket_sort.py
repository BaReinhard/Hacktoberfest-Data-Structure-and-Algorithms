def bucketsort( A ):
  # get hash codes
  code = hashing( A )
  buckets = [list() for _ in range( code[1] )]
  # distribute data into buckets: O(n)
  for i in A:
    x = re_hashing( i, code )
    buck = buckets[x]
    buck.append( i )
 
  # Sort each bucket: O(n).
  # I mentioned above that the worst case for bucket sort is counting
  # sort. That's because in the worst case, bucket sort may end up
  # with one bucket per key. In such case, sorting each bucket would
  # take 1^2 = O(1). Even after allowing for some probabilistic
  # variance, to sort each bucket would still take 2-1/n, which is
  # still a constant. Hence, sorting all the buckets takes O(n).
 
  for bucket in buckets:
    insertionsort( bucket )
 
  ndx = 0
  # merge the buckets: O(n)
  for b in range( len( buckets ) ):
    for v in buckets[b]:
      A[ndx] = v
      ndx += 1
 
import math
 
def hashing( A ):
  m = A[0]
  for i in range( 1, len( A ) ):
    if ( m < A[i] ):
      m = A[i]
  result = [m, int( math.sqrt( len( A ) ) )]
  return result
 
 
def re_hashing( i, code ):
  return int( i / code[0] * ( code[1] - 1 ) )