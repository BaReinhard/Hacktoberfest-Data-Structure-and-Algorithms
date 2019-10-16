class Node {
    constructor(){
        this.end   = false;
        this.children = {};
    }

    setEnd(isEnd) {
        this.end = isEnd;
    }

    addChild(value) {
        if (this.children && this.children.hasOwnProperty(value)) {
            return this.children[value];
        } else {
            let a = new Node();
            this.children[value] = a;
            return a;
        }
    }
}

class Trie {
    constructor() {
        this.root = new Node();
    }

    findPrefix(prefix, parent) {
        if (!parent) { parent = this.root; }
        if (prefix !== null) {
            let letter = prefix.substring(0, 1);
            let remaining = prefix.substring(1);
            if (parent.children.hasOwnProperty(letter)) {
                if (prefix.length === 1) { return true;}
                let result = this.findPrefix(remaining, parent.children[letter]);
                return result;
            } else {
                return false;
            }
        }
    }

    addWord(word, parent = this.root) {
        if (word !== null) {
            let letter = word.substring(0, 1);
            let child = parent.addChild(letter);
            if (word.length > 1) {
                this.addWord(word.substring(1), child);
            } else {
                child.setEnd(true);
            }
        }
    }

    list(root = this.root, word = [], words = []) {
        if (root.end) {
            words.push(word.join(""));
        }

        for (let child in root.children) {
            word.push(child);
            this.list(root.children[child], word, words);
            word.pop();
        }
        return words;
    }
}

// How to use:
// let t = new Trie();
// t.addWord("testing");
// t.addWord("test");
// t.addWord("tesla");
// t.addWord("word");
// t.addWord("work");
// let allwords = t.list();
// console.info(JSON.stringify(t.root));
// console.info(allwords);
// console.info("Prefix test :", t.findPrefix("tes"));
// console.info("Prefix testi :", t.findPrefix("testi"));
// console.info("Prefix word :", t.findPrefix("word"));
// console.info("Prefix war :", t.findPrefix("war"));
// console.info("Prefix c :", t.findPrefix("c"));
// console.info("Prefix testingg :", t.findPrefix("testingg"));
// console.info("Prefix testing2 :", t.findPrefix("testing2"));