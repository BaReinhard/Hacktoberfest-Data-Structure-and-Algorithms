import java.util.ArrayList;

public class Trie {
    public class TrieNode {
        TrieNode[] characters;
        Boolean isEnd = false;

        public TrieNode() {
            characters = new TrieNode[26];
        }
    }

    public static void main(String[] args) {
        new Trie().demo();
    }

    private void demo() {
        TrieNode trie = new TrieNode();
        ArrayList<String> values = new ArrayList<String>() {{
            add("MY");
            add("MANY");
            add("LIE");
            add("A");
            add("AS");
        }};
        for (String s : values) {
            add(trie, s);
        }
        displayTree(trie);
    }

    private void displayTree(TrieNode trie) {
        for (int i = 0; i < trie.characters.length; i++) {
            if (trie.characters[i] != null) {
                DFS(trie.characters[i], new StringBuilder(), i);
            }

        }
    }

    private void DFS(TrieNode n, StringBuilder sb, int index) {
        if (n == null) {
            return;
        }
        sb.append(getCharacter(index));
        for (int i = 0; i < n.characters.length; i++) {
            if (n.characters[i] != null ) {
                DFS(n.characters[i], new StringBuilder(sb), i);
            }
        }
        if (sb.length() != 0 && n.isEnd) {
            System.out.println(sb.toString());
        }
    }

    private void add(TrieNode trie, String s) {
        char[] chars = s.toCharArray();
        TrieNode currentTrie = trie;
        for (Character c : chars) {
            if (currentTrie.characters[getIndex(c)] == null) {
                currentTrie.characters[getIndex(c)] = new TrieNode();
            }
            currentTrie = currentTrie.characters[getIndex(c)];
        }
        currentTrie.isEnd = true;
    }

    public Character getCharacter(int index) {
        return (char) (index + 65);
    }

    public Integer getIndex(Character c) {
        return c - 65;
    }
}
