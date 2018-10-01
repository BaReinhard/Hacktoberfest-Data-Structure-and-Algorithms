
class TrieNode(object):
    """
    A single node in the Trie, representing one character in a sentence.
    """
    def __init__(self, char: str):
        self.char = char
        self.children = []
        self.is_end_of_sentence = False


class Trie(object):
    """
    Implementation of a trie: https://en.wikipedia.org/wiki/Trie
    """
    def __init__(self, root: TrieNode):
        self.root = root

    def add_sentence(self, root: TrieNode, sentence: str):
        """
        Adds a sentence to the Trie, one char at a time, from a given node.
        Args:
            root (TrieNode): the TrieNode at which to begin appending a sentence.
            sentence (str): the str to append below the supplied root.
        Returns:
            the updated Trie.
        """
        character = sentence[0]

        for child in root.children:

            # If the leading char in the string is already a child, no need to add a new node
            if character == child.char:

                # Mark as end of sentence if we are looking at the last char of a string
                if len(sentence) == 1:
                    child.is_end_of_sentence = True
                    return self

                return self.add_sentence(child, sentence[1:])

        # If the leading char is not already a child, append the char as a child of the node
        node = TrieNode(character)

        # Mark as end of sentence if we are looking at the last char of a string
        if len(sentence) == 1:
            node.is_end_of_sentence = True
            root.children.append(node)
            return self

        root.children.append(node)
        return self.add_sentence(node, sentence[1:])

    def return_completions_from_node(self, node: TrieNode, prefix=""):
        """
        Enumerate all possible sentence completions given a prefix.
        Args:
            node (TrieNode): the TrieNode at which to begin our search for possible completions.
            prefix (str): the prefix for which completions are enumerated.
        Returns: 
            a list of str, where each element is a possible completion of the prefix.
        """
        def enumerate_sentences(node: TrieNode, sentence: str, sentences: list, prefix: str):

            if len(node.children) > 0:
                for child in node.children:
                    if child.is_end_of_sentence:
                        sentences.append(prefix + sentence + child.char)
                    if len(child.children) > 0:
                        enumerate_sentences(child, sentence + child.char, sentences, prefix)
                    else:
                        enumerate_sentences(child, sentence, sentences, prefix)

            return sentences

        if node == None:
            return []

        return enumerate_sentences(node, "", [], prefix)

    def contains(self, root: TrieNode, sentence: str):
        """
        Check if a given sentence exists in a Trie, starting at the given node.
        Args:
            root (TrieNode): node at which to begin checking for existence of sentence.
            sentence (str): string to check for existence in the trie.
        Returns:
            (bool, TrieNode)
            (True, last node visited) if a sentence exists in the trie, starting at a given node.
            (False, None) otherwise.
        """
        character = sentence[0]

        for child in root.children:
            if character == child.char:
                if len(sentence) == 1:
                    return (True, child)
                return self.contains(child, sentence[1:])

        return (False, None)
