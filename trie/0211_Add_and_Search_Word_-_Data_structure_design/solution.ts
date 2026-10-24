/*
211. Design Add and Search Words Data Structure
https://leetcode.com/problems/design-add-and-search-words-data-structure/

Note:
word may contain dots '.' where dots can be matched with any letter.
Use a dfs search to search for the word.
*/

class TrieNode {
  value: string | null;
  children = new Map<string, TrieNode>(); // children are stored as Map, where key is the letter and value is a TrieNode for that letter
  isEndOfWord = false; // false by default, a green node means this flag is true

  constructor(value: string | null) {
    this.value = value;
  }
}

class WordDictionary {
  root: TrieNode;
  constructor() {
    this.root = new TrieNode(null);
  }

  addWord(word: string): void {
    let current: TrieNode | undefined = this.root;
    // iterate through all the characters of word
    for (let character of word) {
      // if node doesn't have the current character as child, insert it
      if (current && current.children.get(character) === undefined) {
        current.children.set(character, new TrieNode(character));
      }
      // move down, to insert next character
      current = current?.children.get(character);
    }
    // mark the last inserted character as end of the word
    if (current) {
      current.isEndOfWord = true;
    }
  }

  search(word: string): boolean {
    return this.dfsSearch(word, 0, this.root);
  }

  private dfsSearch(word: string, index: number, node: TrieNode): boolean {
    if (index === word.length) {
      return node.isEndOfWord;
    }

    const ch = word[index];
    if (ch !== ".") {
      const child = node.children.get(ch);
      if (child && this.dfsSearch(word, index + 1, child)) {
        return true;
      }
    } else {
      for (const child of node.children.values()) {
        if (child && this.dfsSearch(word, index + 1, child)) {
          return true;
        }
      }
    }
    return false;
  }
}

export {};
