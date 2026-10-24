/*
1268. Search Suggestions System

https://leetcode.com/problems/search-suggestions-system
*/

function suggestedProducts(products: string[], searchWord: string): string[][] {
  // Init trie
  const trie = new Trie();
  trie.insertWords(products);

  const res = [];
  // search the prefix
  let substr = "";
  for (const char of searchWord) {
    substr += char;
    const words = trie.getSuggestionForPrefix(substr, 3);
    res.push(words);
  }

  return res;
}

// Trie implementation
class TrieNode {
  isWord: boolean;
  prefix: string;
  children: { [key: string]: TrieNode };

  constructor() {
    this.isWord = false;
    this.prefix = "";
    this.children = {}; // char-> children
  }
}

class Trie {
  root: TrieNode;

  constructor() {
    this.root = new TrieNode();
  }

  insertWords(words: string[]) {
    for (const word of words) {
      this.insertWord(word);
    }
  }

  insertWord(word: string) {
    let curr = this.root;

    for (let i = 0; i < word.length; i++) {
      const c = word.charAt(i);
      if (!curr.children[c]) {
        curr.children[c] = new TrieNode();
        // store the prefix at each node
        curr.children[c].prefix = word.substring(0, i + 1);
      }
      curr = curr.children[c];
    }
    curr.isWord = true;
  }

  /*
  根据给定的前缀 prefix，返回最多 limit 个以该前缀开头的建议单词。
  */
  getSuggestionForPrefix(prefix: string, limit: number): string[] {
    const results: string[] = [];
    let curr = this.root;
    // Traverse to the end of the prefix
    for (let i = 0; i < prefix.length; i++) {
      const c = prefix.charAt(i);
      if (curr.children[c]) {
        curr = curr.children[c];
      } else {
        return [];
      }
    }
    // Start DFS from the end of the prefix to find suggestions
    this.findSuggestion(curr, results, limit);
    return results;
  }

  /*
    DFS to find suggestions in lexicographical order
   */
  findSuggestion(node: TrieNode, results: string[], limit: number) {
    if (node == null || results.length === limit) return;

    if (node.isWord === true) {
      results.push(node.prefix);
    }

    for (let i = 0; i < 26; i++) {
      const char = String.fromCharCode(i + 97);
      this.findSuggestion(node.children[char], results, limit);
    }
  }
}
export {};
