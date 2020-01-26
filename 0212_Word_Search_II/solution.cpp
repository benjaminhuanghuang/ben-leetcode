/*
212. Word Search II

Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" 
cells are those horizontally or vertically neighboring. 

The same letter cell may not be used more than once in a word.

https://leetcode.com/problems/word-search-ii/
*/
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution2
{
public:
  //data structure
  class Trie
  {
  public:
    struct TrieNode
    {
      TrieNode() : word(""), children(26, nullptr) {}

      ~TrieNode()
      {
        for (TrieNode *child : children)
          if (child)
            delete child;
      }

      string word;
      vector<TrieNode *> children;
    };
    // Constructor init the root node
    Trie() : root(new TrieNode())
    {
    }
    // Inserts a word into the trie.
    void insert(string &word)
    {
      TrieNode *node = root.get();
      for (char c : word)
      {
        int idx = c - 'a';
        if (node->children[idx] == nullptr)
        {
          node->children[idx] = new TrieNode();
        }
        node = node->children[idx];
      }
      node->word = word;
    }
    unique_ptr<TrieNode> root;
  };

  vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
  {
    Trie trie;
    vector<string> ans;
    for (string word : words)
    {
      trie.insert(word);
    }
    int rows = board.size();
    int cols = board[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    for (int row = 0; row < rows; row++)
    {
      for (int col = 0; col < cols; col++)
      {
        Trie::TrieNode *node = trie.root.get()->children[board[row][col] - 'a'];
        if(node!=nullptr)
          dfs(board, node, row, col, visited, ans);
      }
    }

    return ans;
  }

private:
  vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  void dfs(vector<vector<char>> &board, Trie::TrieNode *p, int row, int col, vector<vector<bool>> &visited, vector<string> &ans)
  {
     if(p == nullptr || visited[row][col])
        return;
    if (!p->word.empty())
    {
      ans.push_back(p->word);
      p->word.clear();
    }
    visited[row][col] = true;

    for (auto d : dirs)
    {
      int nRow = row + d.first;
      int nCol = col + d.second;
      if(nRow < 0 || nRow >= board.size() || nCol < 0 || nCol >= board[0].size())
      {
        // 因为要使用 children[board[nx][ny], 所以要立即检查数组越界，不能把这个判断放到function开始的地方！
        continue;
      }
      dfs(board, p->children[board[nRow][nCol] - 'a'], nRow, nCol, visited, ans);
    }
    visited[row][col] = false;
  }
};

class Solution
{
public:
  //data structure
  class Trie
  {
  public:
    struct TrieNode
    {
      TrieNode() : isWordEnd(false), isUsed(false), children(26, nullptr) {}

      ~TrieNode()
      {
        for (TrieNode *child : children)
          if (child)
            delete child;
      }

      bool isWordEnd;
      bool isUsed;
      vector<TrieNode *> children;
    };
    // Constructor init the root node
    Trie() : root(new TrieNode())
    {
    }
    // Inserts a word into the trie.
    void insert(string &word)
    {
      TrieNode *node = root.get();
      for (char c : word)
      {
        if (node->children[c - 'a'] == nullptr)
        {
          node->children[c - 'a'] = new TrieNode();
        }
        node = node->children[c - 'a'];
      }
      node->isWordEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string &word)
    {
      TrieNode *node = root.get();
      for (char c : word)
      {
        if (node->children[c - 'a'] == nullptr)
          return false;
        node = node->children[c - 'a'];
      }
      if (node->isWordEnd)
      {
        if (node->isUsed)
          return false;
        node->isUsed = true;
        return true;
      }
      return false;
    }
    // Returns if the word is in the trie.
    bool startWith(string &word)
    {
      TrieNode *node = root.get();
      for (char c : word)
      {
        if (node->children[c - 'a'] == nullptr)
          return false;
        node = node->children[c - 'a'];
      }
      return true;
    }

  private:
    unique_ptr<TrieNode> root;
  };

  vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
  {
    Trie trie;
    vector<string> ans;
    for (string word : words)
    {
      trie.insert(word);
    }

    int rows = board.size();
    int cols = board[0].size();
    for (int row = 0; row < rows; row++)
    {
      for (int col = 0; col < cols; col++)
      {
        dfs(board, row, col, "", trie, ans);
      }
    }

    return ans;
  }

private:
  void dfs(vector<vector<char>> &board, int row, int col, string word, Trie &trie, vector<string> &ans)
  {
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
      return;

    char cur = board[row][col];
    if (cur == 0)
      return;

    word += cur;
    if (!trie.startWith(word))
      return;

    if (trie.search(word))
    {
      ans.push_back(word);
    }
    board[row][col] = 0; // 小技巧，防止重入
    dfs(board, row - 1, col, word, trie, ans);
    dfs(board, row + 1, col, word, trie, ans);
    dfs(board, row, col - 1, word, trie, ans);
    dfs(board, row, col + 1, word, trie, ans);
    board[row][col] = cur;
  }
};

int main()
{
  Solution2 s;
  vector<vector<char>> board{{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
  vector<string> words{"oath", "pea", "eat", "rain"};
  s.findWords(board, words);
}