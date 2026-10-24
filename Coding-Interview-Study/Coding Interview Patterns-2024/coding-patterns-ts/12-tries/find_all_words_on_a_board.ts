class TrieNode {
  children: Map<string, TrieNode>;
  word: string | null;

  constructor() {
    this.children = new Map<string, TrieNode>();
    this.word = null; // store the word at the end node
  }
}

function findAllWordsOnBoard(board: string[][], words: string[]): string[] {
  const root = new TrieNode();

  // Step 1: Build the Trie
  for (const word of words) {
    let node = root;
    for (const char of word) {
      if (!node.children.has(char)) {
        node.children.set(char, new TrieNode());
      }
      node = node.children.get(char)!;
    }
    node.word = word; // mark the end of the word
  }

  const res: string[] = [];
  const rows = board.length;
  const cols = board[0].length;

  // Step 2: DFS function
  function dfs(r: number, c: number, node: TrieNode) {
    const char = board[r][c];
    if (!node.children.has(char)) return;

    const nextNode = node.children.get(char)!;

    if (nextNode.word !== null) {
      res.push(nextNode.word);
      nextNode.word = null; // avoid duplicates
    }

    board[r][c] = "#"; // mark visited

    const directions = [
      [0, 1],
      [1, 0],
      [0, -1],
      [-1, 0],
    ];

    for (const [dr, dc] of directions) {
      const nr = r + dr;
      const nc = c + dc;
      if (
        nr >= 0 &&
        nr < rows &&
        nc >= 0 &&
        nc < cols &&
        board[nr][nc] !== "#"
      ) {
        dfs(nr, nc, nextNode);
      }
    }

    board[r][c] = char; // restore after DFS
  }

  // Step 3: Start DFS from each cell
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (root.children.has(board[r][c])) {
        dfs(r, c, root);
      }
    }
  }

  return res;
}

// DFS helper function
function dfs(
  board: string[][],
  r: number,
  c: number,
  node: TrieNode,
  res: string[]
): void {
  // If the current node represents the end of a word, add it to the result
  if (node.word !== null) {
    res.push(node.word);
    node.word = null; // Ensure the word is added only once
  }

  const temp = board[r][c];
  board[r][c] = "#"; // Mark the current cell as visited

  const directions = [
    [-1, 0], // up
    [1, 0], // down
    [0, -1], // left
    [0, 1], // right
  ];

  for (const [dr, dc] of directions) {
    const nextR = r + dr;
    const nextC = c + dc;

    if (
      isWithinBounds(nextR, nextC, board) &&
      node.children.has(board[nextR][nextC])
    ) {
      dfs(board, nextR, nextC, node.children.get(board[nextR][nextC])!, res);
    }
  }

  board[r][c] = temp; // Backtrack: restore the cell
}

// Helper function to check if coordinates are within board bounds
function isWithinBounds(r: number, c: number, board: string[][]): boolean {
  return r >= 0 && r < board.length && c >= 0 && c < board[0].length;
}

/*
Complexity Analysis
Time complexity: The time complexity of find_all_words_on_a_board is O(N · L + m · n • 3L)
where N denotes the number of words in the words array, L denotes the length of the longest
word, and m · n denotes the size of the board. Here's why:
• To build the trie, we insert each word from the input array into it, with each word containing
a maximum of L characters. This takes O(N • L) time.
• Then, in the main search process, we perform a DFS for each of them· n cells on the board.
Each DFS call takes 0(3L) time because, at each point in the DFS, we make up to 3 recursive
calls : one for each of the 3 adjacent cells (this excludes the cell we came from). This is repeated
for, at most, the length of the longest word, L.
Therefore, the overall time complexity is O(N . L) + m. n . O(3^L) = O(N • L + m · n · 3^L).

Space complexity: The space complexity is O(N • L). Here's why:
• The trie has a space complexity of O(N . L). In the worst case, if all words have unique prefixes,
we store every character of every word in the trie. Each word attribute stored at the end of
a path in the trie takes O(L) space, and with N words. This contributes an additional O(N • L)
space.
• The maximum depth of the recursive call stack is L.
Therefore, the overall space complexity is O(N. L) + O(L) = O(N • L).
*/
