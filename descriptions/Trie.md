## ELI5
Trie is an information re'trie'val data container.It's a tree useful in searching strings.
USES:Autocomplete in text messages etc.
### Pros
* Searching is easier and faster.
### Cons
* Storage takes more space.

## Technical Explaination
A Trie, also called a digital tree or prefix tree, is a search tree that is used to store a dynamic set or associative array.The keys of a Trie are mostly strings.The postition of node in tree defines its key. All the descendants of a node have a common prefix of the string associated with that node, and the root is associated with the empty string.
Each brach of tree represents a character.
* isEndOfWord : It is the last node of a word.

### Pros
* Search in trie is O(M) where M is length of the key. Faster than BST.
### Cons
* Tries can be slower in some cases than hash tables for looking up data
* Require more space.
