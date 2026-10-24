export class TrieNode {
  // 节点只通过 children 的键来知道自己是哪个字符
  children: Map<string, TrieNode>;
  isWord: boolean;

  constructor() {
    this.children = new Map<string, TrieNode>();
    this.isWord = false;
  }
}
