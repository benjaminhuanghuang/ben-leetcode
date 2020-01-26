/*
830. Positions of Large Groups

https://leetcode.com/problems/positions-of-large-groups/


  一个字符串.若连续的字母为3个或3个以上.则称为一个 large group.
  求出所有 large group 的起始,结束位置索引.

*/
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  vector<vector<int>> largeGroupPositions(string S)
  {
    vector<vector<int>> res;
    for (int i = 0, j = 0; i < S.size(); i = j)
    {
      while (j < S.size() && S[j] == S[i])
        ++j;
      if (j - i >= 3)
        res.push_back({i, j - 1});
    }
    return res;
  }
};