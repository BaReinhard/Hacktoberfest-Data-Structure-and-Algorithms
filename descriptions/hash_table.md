
## ELI5

Hash Table is an array to store values(keys/value pairs) into buckets corresponding to some property.

### Pros

* Faster search,insertion and  deletion operations.

### Cons

* Hash tables can be difficult to implement.

*Hash tables are not effectively fast when the number of entries is very small.

*Enteries that need to be stored in same bucket cause 'collisions'.

## Technical Explaination

A hash table (hash map) is a data structure which implements an associative array abstract data type,and maps keys to values.
### Hash Function :
 A hash table uses a hash function to compute an index into an array of buckets, from which the desired element can be found.
A good hash function and implementation algorithm are essential for good hash table performance.
### Collisions :
Since a hash function gets us a small number for a big key, there is possibility that two keys result in same value. The situation where a newly inserted key maps to an already occupied slot in hash table is called collision.
COLLISION HANDLING METHODS:
1.Chaining
2.Open addressing


### Pros

*Hash Table supports following operations in Θ(1) time.
1) Search
2) Insert
3) Delete

### Cons

*Hash tables become quite inefficient when there are many collisions.

*For certain string processing applications, such as spell-checking, hash tables may be less efficient than tries, finite automata, or Judy arrays. 

*Hash tables in general exhibit poor locality of reference—that is, the data to be accessed is distributed seemingly at random in memory.
