# Trie

```js
export class TrieNode {
  // 节点只通过 children 的键来知道自己是哪个字符
  children: Map<string, TrieNode>;
  isWord: boolean;

  constructor() {
    this.children = new Map<string, TrieNode>();
    this.isWord = false;
  }
}


class TrieNode {
  value: string | null;   // Node has value
  children = new Map<string, TrieNode>(); // children are stored as Map, where key is the letter and value is a TrieNode for that letter
  isEndOfWord = false; // false by default, a green node means this flag is true

  constructor(value: string | null) {
    this.value = value;
  }
}
```
