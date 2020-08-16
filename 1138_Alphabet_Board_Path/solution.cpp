/*
1138. Alphabet Board Path

Level: Medium

https://leetcode.com/problems/alphabet-board-path
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class Solution
{
public:
  string alphabetBoardPath(string target)
  {
    vector<vector<string>> paths(26, vector<string>(26));
    // caulculate the moves from source to target.
    for (int s = 0; s < 26; ++s)
      for (int t = 0; t < 26; ++t)
      {
        int dx = t % 5 - s % 5;
        int dy = t / 5 - s / 5;
        string path;
        while (dx < 0)
        {
          path.push_back('L');
          dx++;
        }
        while (dy < 0)
        {
          path.push_back('U');
          dy++;
        }
        while (dx > 0)
        {
          path.push_back('R');
          dx--;
        }
        while (dy > 0)
        {
          path.push_back('D');
          dy--;
        }
        paths[s][t] = path;
      }

    char last = 'a';
    string ans;
    for (char curr : target)
    {
      ans += paths[last - 'a'][curr - 'a'] + "!";
      last = curr;
    }
    return ans;
  }
};