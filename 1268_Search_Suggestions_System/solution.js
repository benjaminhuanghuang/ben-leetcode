/*
1268. Search Suggestions System

Level: Medium

https://leetcode.com/problems/search-suggestions-system
*/

/*
  Solution: 
*/
class Node {
    constructor() {
        this.isWord = false;
        this.children = new Array(26).fill(null);
    }
}

class Trie {
    constructor() {
        this.root = new Node();
    }
    
    insert(word) {
        this.insertHelper(this.root, word, 0);
    }

    insertHelper(node, word, charIndex) {
        if (node == null) {
            node = new Node();
        }
        if (charIndex == word.length) {
            node.isWord = true;
            return node;
        }
        
        const index = word.charCodeAt(charIndex) - 97;
        
        node.children[index] = this.insertHelper(node.children[index], word, charIndex + 1);
        
        return node;
    }
    
    insertWords(words) {
        for (const word of words) {
            this.insert(word);
        }
    }
    
    get(word) {
        return this.getHelper(this.root, word, 0);
    }
    
    getHelper(node, word, charIndex) {
        if (node == null || charIndex === word.length) {
            return node;
        }
    
        const index = word.charCodeAt(charIndex) - 97;
        return this.getHelper(node.children[index], word, charIndex + 1);
    }
    
    keysWithPrefix(prefix, limit) {
        const queue = [];
        this.collect(this.get(prefix), prefix, queue, limit);
        return queue;
    }
    
    collect(node, prefix, queue, limit) {
        if (node == null || queue.length === limit) return;
		
        if (node.isWord === true) {
            queue.push(prefix);
        }
        
        for (let i = 0; i < 26; i++) {
            const char = String.fromCharCode(i + 97);
            this.collect(node.children[i], prefix + char, queue, limit);
        }
    }
}

/**
 * @param {string[]} products
 * @param {string} searchWord
 * @return {string[][]}
 */
var suggestedProducts = function(products, searchWord) {
    const trie = new Trie();
    trie.insertWords(products);
    const res = [];
    let substr = "";
    
    for (const char of searchWord) {
        substr += char;
        const words = trie.keysWithPrefix(substr, 3);
        res.push(words);
    }
    
    return res;
};