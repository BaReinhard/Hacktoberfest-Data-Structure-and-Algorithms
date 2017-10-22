/*
 * Written By Tom Bowden @bowdens for Hacktoberfest 2017.
 * probably not the best or most feature rich implementation of a trie
 * that you'll ever see, but anyway.
 * Not super efficient either because each letter is stored as a single char,
 * no use of subdividing words up.
 */

#ifndef _TRIE_H
#define _TRIE_H

typedef struct trieNode* Trie;

//creates an empty Trie
Trie TrieCreate(void);

int TrieWordExists(Trie t, char *word);
int TrieWordFreq(Trie t, char *word);
int TrieTotalWords(Trie t);
int TrieTotalUniqueWords(Trie t);

//currently only allows for letters a..z
void TrieAddWord(Trie t, char *word);
void TrieDrop(Trie t);


void TrieShow(Trie t);

#endif
