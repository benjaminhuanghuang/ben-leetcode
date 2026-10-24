class TrieNode {
  value: string | null;
  children = new Map<string, TrieNode>(); // children are stored as Map, where key is the letter and value is a TrieNode for that letter
  isEndOfWord = false; // false by default, a green node means this flag is true

  constructor(value: string | null) {
    this.value = value;
  }
}

/*
    insert:
    search:
    hasAllPrefixes:
*/
class Trie {
  root: TrieNode;

  constructor() {
    this.root = new TrieNode(null);
  }

  insert(word: string) {
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

  search(word: string) {
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
    return current?.isEndOfWord;
  }

  hasAllPrefixes(word: string): boolean {
    let current: TrieNode | undefined = this.root;
    for (const character of word) {
      if (current?.children.get(character) === undefined) {
        // could not find this character in sequence, return false
        return false;
      }
      // move down, to match next character
      current = current.children.get(character);
      if (current?.isEndOfWord) {
        // make sure it is prefix, not a word
        return false;
      }
    }
    return true; // not return current?.isEndOfWord, because we need to check all prefixes
  }
}

export { Trie, TrieNode };
