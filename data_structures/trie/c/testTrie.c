#include <stdio.h>
#include <assert.h>
#include "trie.h"

#define TOTALWORDS 9

int main(void){
    assert(TrieWordExists(NULL,"test") == 0);
    assert(TrieWordFreq(NULL,"test") == 0);
    assert(TrieTotalWords(NULL) == 0);
    assert(TrieTotalUniqueWords(NULL) == 0);

    char *strs[TOTALWORDS] = {"test", "test", "text", "test", "apply", "a", "apple", "chair", "chairman"};
    Trie t = TrieCreate();
    assert(TrieWordExists(t, "test") == 0);
    assert(TrieWordFreq(t, "test") == 0);
    assert(TrieTotalWords(t) == 0);
    assert(TrieTotalUniqueWords(t) == 0);

    assert(TrieWordExists(t,NULL) == 0);
    assert(TrieWordFreq(t, NULL) == 0);

    for(int i = 0; i < TOTALWORDS; i++){
        TrieAddWord(t, strs[i]);
    }
    for(int i = 0; i < TOTALWORDS; i++){
        assert(TrieWordExists(t,strs[i]));
        assert(TrieWordFreq(t,strs[i]) == (i==0 || i==1 || i==3)?2:1);
    }
    assert(TrieWordExists(t, "tests") == 0);
    assert(TrieWordFreq(t,"tests") == 0);
    assert(TrieTotalWords(t) == TOTALWORDS);
    assert(TrieTotalUniqueWords(t) == TOTALWORDS - 2);

    TrieShow(t);

    TrieDrop(t);
}
