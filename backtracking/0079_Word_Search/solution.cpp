#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

/*
http://zxi.mytechroad.com/blog/leetcode/leetcode-79-word-search/

Time complexity: O(m*n*4^l)
search 4 direction, l = len(word) , Time = 4 * 4 * 4....
Space complexity: O(m*n+ l), m*n 为输入，l为递归深度
*/
class Solution
{
public:
  bool exist(vector<vector<char>> &board, string word)
  {
    if (board.size() == 0)
      return false;
    h = board.size();
    w = board[0].size();

    // Search every cell
    for (int i = 0; i < w; i++)
      for (int j = 0; j < h; j++)
        if (search(board, word, 0, i, j))
          return true;
    return false;
  }

private:
  int w;
  int h;
  bool search(vector<vector<char>> &board, const string &word, int pos, int x, int y)
  {
    if (x < 0 || x == w || y < 0 || y == h || word[pos] != board[y][x])
      return false;

    // Found the last char of the word
    if (pos == word.length() - 1)
      return true;

    char cur = board[y][x];  // backup
    board[y][x] = 0;  // 小技巧，防止重入
    // Search 4 directions
    bool found = search(board, word, pos + 1, x + 1, y) || search(board, word, pos + 1, x - 1, y) || search(board, word, pos + 1, x, y + 1) || search(board, word, pos + 1, x, y - 1);
    board[y][x] = cur;
    return found;
  }
};
