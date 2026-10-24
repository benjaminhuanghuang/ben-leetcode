/*
208. Implement Trie (Prefix Tree)
https://leetcode.com/problems/implement-trie-prefix-tree/
*/

/*
    Time complexity - O(N) - N as number of words in the trie
    Space complexity - O(N) - N as number of words in the trie
*/
class TrieNode {
  value: string | null;
  children = new Map<string, TrieNode>(); // children are stored as Map, where key is the letter and value is a TrieNode for that letter
  isEndOfWord = false; // false by default

  constructor(value: string | null) {
    this.value = value;
  }
}

class Trie {
  root: TrieNode;

  constructor() {
    this.root = new TrieNode(null);
  }

  insert(word: string): void {
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
    let current: TrieNode | undefined = this.root;
    // iterate through all the characters of word
    for (let character of word) {
      if (current?.children.get(character) === undefined) {
        // could not find this character in sequence, return false
        return false;
      }
      // move down, to match next character
      current = current.children.get(character);
    }
    // found all characters, return true if last character is end of a word
    return current!.isEndOfWord;
  }

  startsWith(prefix: string): boolean {
    let curr = this.root;
    for (let character of prefix) {
      if (curr?.children.get(character) === undefined) {
        return false;
      }

      curr = curr.children.get(character)!;
    }

    return true;
  }
}
export {};
