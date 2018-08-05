//written by Tom Bowden (@bowdens) October 2017

//A Trie interface which accpets letters from a to z. Each word also has a list of urls that is associated with it
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "trie.h"

#define LETTERS 26 //number of allowed letters, a-z for now
#define INVALID -1 //used to determine if a char is a valid index or not

#define MAXPRINTLEN 1000

/*
 * ------POSSIBLE LETTERS--------
 *  (a=0), (b=1), ..., (z=25)
 */

typedef struct trieNode{
    struct trieNode *child[LETTERS];
    int freq;
} TrieNode;

int charToIndex(char c){
    /*
     * returns the index of a given char
     * returns INVALID if it is not a valid index
     */
    c = tolower(c);
    if(c < 'a' || c > 'z') return INVALID;
    return c - 'a';
}

char indexToChar(int i){
    /*
     * converts an index into a char
     * returns INVALID if it is not a valid index
     */

    if(i < 0 || i > LETTERS) return INVALID;
    return i + 'a';
}

int validWord(char *word){
    /*
     * returns 1 if the provided char* is a valid word
     * (all of its letters are valid)
     * returns 0 if it is not a valid word
     */

    if(word == NULL) return 0;
    int len = strlen(word);
    for(int i = 0; i < len; i++){
        if(charToIndex(word[i]) == INVALID) return 0;
    }
    return 1;
}


Trie TrieCreate(void){
    /*
     * creates an empty trie/trie node
     */

    Trie t = malloc(sizeof(TrieNode));
    assert(t);
    assert(t->child);

    for(int i = 0; i < LETTERS; i++){
        t->child[i] = NULL;
    }
    t->freq = 0;
    return t;
}

void TrieAddWord(Trie t, char *word){
    /*
      adds a word to a trie. If it already exists,
      Add the url to the list of urls. If the url
      already exists, increment the frequency for
      that url.
     */
    //error checking
    if(t == NULL) return;
    if(!validWord(word)) return;

    Trie temp = t;

    int len = strlen(word);
    for(int i = 0; i < len; i++){
        int letterIndex = charToIndex(word[i]);
        if(temp->child[letterIndex] == NULL){
            //we have not seen this letter in this position before
            temp->child[letterIndex] = TrieCreate();
        }
        temp = temp->child[letterIndex];
        if(i == len-1){
            temp->freq++;
        }
    }
}

Trie TrieFindWord(Trie t, char *word){
    /*
     * returns a pointer to the trie
     * that is at the end of this word.
     * for example, TrieFindWord(t, "ace")
     * would return the pointer to the 'e'
     * in ace if it existed, and NULL otherwise
     */

    if(t == NULL) return NULL;
    if(word == NULL) return NULL;
    Trie temp = t;
    int len = strlen(word);
    for(int i = 0; i < len; i++){
        //loops through each letter moving the temp down the trie until the end of the word is reached
        // or the trie does not have the word in it
        int index = charToIndex(word[i]);
        if(index == INVALID) return NULL;
        if(temp->child[index] == NULL) return NULL;
        temp = temp->child[index];
    }
    //temp will be the final position of the word
    return temp;
}


void printTrie(Trie t, char buffer[MAXPRINTLEN], int index, char nextChar){
    /*
     * Recursively prints each word in the trie
     */

    //error checking
    if(t == NULL) return;
    if(index < -1) return;
    if(buffer == NULL) return;


    //copy the buffer into a new buffer, append the next character to be added
    char newBuffer[MAXPRINTLEN] = {0};
    strcpy(newBuffer, buffer);
    if(index != -1){
        //if the index is -1 then that indicates we are at the start of the recursive calls. do not add anything to the buffer
        newBuffer[index] = nextChar;
    }
    index++;

    //if a word has been found, print it
    if(t->freq > 0){
        //we have found a word, print it
        printf("%s\n",newBuffer);
    }

    //for each possible next letter, recursively call this function
    for(int i = 0; i < LETTERS; i++){
        if(t->child[i]){
            printTrie(t->child[i], newBuffer, index, indexToChar(i));
        }
    }
}

void TrieShow(Trie t){
    /*
     * Prints out each word in the trie alphabetically to stdout
     */
    char buffer[MAXPRINTLEN] = {0};
    printTrie(t,buffer,-1,'a');
}

int TrieWordFreq(Trie t, char *str){
    /*
     * returns the frequency of str if it exists in the trie, 0 otherwise
     * returns 0 if the str is NULL or t is NULL
     */
    if(t == NULL) return 0;
    if(!validWord(str)) return 0;

    Trie temp = t;
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        int index = charToIndex(str[i]);
        if(temp->child[index] == NULL) return 0;
        temp = temp->child[index];
    }
    return temp->freq;
}

int TrieWordExists(Trie t, char *str){
    /*
     * returns 1 if str exists in the trie, 0 otherwise
     */
    return TrieWordFreq(t,str) != 0;
}

int TrieTotalWords(Trie t){
    /*
     * counts up all the words in the trie
     * this include words with frequencies greater than 1.
     * If the word "test" was added to the trie 3 times, then this function would coun that as 3 words
     * returns 0 if the trie is NULL
     */
    if(t == NULL) return 0;
    int count = 0;
    for(int i = 0; i < LETTERS; i++){
        count += TrieTotalWords(t->child[i]);
    }
    return count + t->freq;
}

int TrieTotalUniqueWords(Trie t){
    /*
     * Counts the number of unique words in the trie
     * returns 0 if the trie is NULL
     */
    if(t == NULL) return 0;
    int count = 0;
    for(int i = 0; i < LETTERS; i++){
        count += TrieTotalUniqueWords(t->child[i]);
    }
    return count + (t->freq!=0);
}

void TrieDrop(Trie t){
    /*
     * frees all the memory in the trie
     */
    if(t == NULL) return;
    for(int i = 0; i < LETTERS; i++){
        TrieDrop(t->child[i]);
    }
    free(t);
}
