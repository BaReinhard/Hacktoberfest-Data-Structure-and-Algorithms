endOfWord = "$"
def generateTrieFromWordsArray(words):
   root = {}
   for word in words:
      currentDict = root
      for letter in word:
         currentDict = currentDict.setdefault(letter, {})
      currentDict[endOfWord] = endOfWord
   return root


 def isWordPresentInTrie(trie, word):
   currentDict = trie
   for letter in word:
      if letter in currentDict:
         currentDict = currentDict[letter]
      else: 
         return False
   return endOfWord in currentDict 