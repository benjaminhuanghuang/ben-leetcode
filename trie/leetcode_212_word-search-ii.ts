/*
212. Word Search II
https://leetcode.com/problems/word-search-ii/
*/

/*
Insert O(L) - L is the length of the word
Search O(L) - L is the length of the word

Space complexity: O(N * L) - N is the number of words, L is the length of the word
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

/*
N = number of words in the list
L = maximum length of each word

In the worst case, we might end up visiting all the words in the list, and for each word, we try changing each letter (where there are 26 possibilities for each letter change). 
Therefore, the time complexity can be expressed as O(L * 26 * N).

However, the bidirectional search potentially halves the search space since we 
progress from both ends and stop when we meet in the middle, which can reduce the 
time complexity to approximately O(L * 26 * N / 2), 
though in Big O notation, we still represent it as O(L * 26 * N) since constant factors 
are not considered.

Since we store at most every word in these structures, the space complexity is O(N).
https://algo.monster/liteproblems/127
*/
function findWords(board: string[][], words: string[]): string[] {
  const trie = new Trie();
  for (let word of words) {
    trie.insert(word);
  }

  const result: string[] = [];

  const dfs = (i: number, j: number, node: TrieNode, path: string) => {
    if (
      i < 0 ||
      i >= board.length ||
      j < 0 ||
      j >= board[0].length ||
      board[i][j] === "#"
    ) {
      return;
    }

    const ch = board[i][j];
    const child = node.children.get(ch);
    if (!child) {
      return;
    }

    path += ch;
    if (child.isEndOfWord) {
      result.push(path);
      child.isEndOfWord = false;
    }

    board[i][j] = "#";
    dfs(i + 1, j, child, path);
    dfs(i - 1, j, child, path);
    dfs(i, j + 1, child, path);
    dfs(i, j - 1, child, path);
    board[i][j] = ch;
  };

  for (let i = 0; i < board.length; i++) {
    for (let j = 0; j < board[0].length; j++) {
      dfs(i, j, trie.root, "");
    }
  }

  return result;
}
