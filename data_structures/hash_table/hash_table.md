# ELI5
A hashtable is a data structure that maps a key to a value using a hash function. You can imagine a hashtable as a dictionary (the book). In a dictionary, we look up a word (the key), and find the definition (a value).

## Pros
- On average, searching, insertion, and deletions are fast

## Cons
- In the worst case, searching, insertion and deletions are expensive

# Technical Explanation
A hashtable is generally initialized with a size internally. We first start off with an empty hashtable, and we'll be mapping keys to values. Hash tables use a hash function to map a key to a bucket which stores the value. Ideally, we want our hash function to assign each key to a unique bucket. When we are able to map each key to a unique bucket, we say that we have a perfect hash function. In general, a perfect hash function is virtually impossible. In the case of a perfect hash function, we are able to achieve O(1) time for searching, insertion, and deletion. However, if more than one key maps to a bucket, we say that we have a hashing collision.
In situations like this, there are various solutions you can employ to resolve this. One of them is linear probing. Linear probing is a solution that is employed when two keys map to the same bucket. In this case the key is then mapped to the closest empty bucket. 

# Pros
- With a perfect hash function, searching, insertion and deletions are O(1). In other words, the average case is O(1)

# Cons
- In the case of hashing collision, searching, insertion and deletions are O(n)
