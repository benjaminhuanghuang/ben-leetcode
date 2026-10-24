import { TrieNode } from "./TrieNode";

class Trie {
  private root: TrieNode;

  constructor() {
    this.root = new TrieNode();
  }

  insert(word: string): void {
    let node = this.root;
    for (const char of word) {
      if (!node.children.has(char)) {
        node.children.set(char, new TrieNode());
      }
      node = node.children.get(char)!;
    }
    node.isWord = true;
  }

  search(word: string): boolean {
    let node = this.root;
    for (const char of word) {
      if (!node.children.has(char)) return false;
      node = node.children.get(char)!;
    }
    return node.isWord;
  }

  hasPrefix(prefix: string): boolean {
    let node = this.root;
    for (const char of prefix) {
      if (!node.children.has(char)) return false;
      node = node.children.get(char)!;
    }
    return true;
  }
}

/*
Time complexity:
• The time complexity of insert is O(k), where k is the length of the word being inserted. This Is
because we traverse through or insert up to k nodes into the trie in each iteration.
• The time complexity of search and has_prefix is O(k) because we search through at most k
characters in the trie.

Space complexity:
• The space complexity of insert is O(k) because in the worst case, the inserted word doesn't
share any prefix with words already in the trie. In this case, k new nodes are created.
• The space complexity of search and has_prefix is O(1) because no additional space is used
to traverse the search term in the trie.
*/
