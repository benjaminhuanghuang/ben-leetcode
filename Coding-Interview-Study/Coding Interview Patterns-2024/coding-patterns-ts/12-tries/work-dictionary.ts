import { TrieNode } from "./TrieNode";
class WordDictionary {
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
    return this.searchHelper(0, word, this.root);
  }

  private searchHelper(index: number, word: string, node: TrieNode): boolean {
    for (let i = index; i < word.length; i++) {
      const char = word[i];

      if (char === ".") {
        for (const child of node.children.values()) {
          if (this.searchHelper(i + 1, word, child)) {
            return true;
          }
        }
        return false;
      } else if (node.children.has(char)) {
        node = node.children.get(char)!;
      } else {
        return false;
      }
    }

    return node.isWord;
  }
}
