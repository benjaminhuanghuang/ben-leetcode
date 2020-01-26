/*
691. Stickers to Spell Word

https://leetcode.com/problems/stickers-to-spell-word/
*/

#include <vector>
#include <string>
#include <map>

using namespace std;

/*
  https://blog.csdn.net/JackZhang_123/article/details/78891978
*/
class Solution
{
public:
  int minStickers(vector<string> &stickers, string target)
  {
    //把所有的字符按照数组存进去
    vector<vector<int>> all(stickers.size(), vector<int>(26, 0));
    for (int i = 0; i < stickers.size(); i++)
    {
      for (char c : stickers[i])
      {
        all[i][c - 'a']++;
      }
    } //中间结果的保存查询
    map<string, int> dp;
    dp[""] = 0;
    return dfs(all, dp, target);
  }

private:
  int dfs(vector<vector<int>> &all, map<string, int> &dp, string target)
  {
    if (dp.find(target) != dp.end())
      return dp[target];
    else
    {
      //统计目标字符串
      vector<int> tar(26, 0);
      for (char c : target)
        tar[c - 'a']++;
      //针对每一个字典中的字符串依次做处理
      int minStep = INT_MAX;
      for (int i = 0; i < all.size(); i++)
      {
        //优化，加速计算
        if (all[i][target[0] - 'a'] == 0)
          continue;
        string res;
        for (int j = 0; j < 26; j++)
        {
          if (tar[j] >= all[i][j])
            res += string(tar[j] - all[i][j], 'a' + j);
        }
        int tmp = dfs(all, dp, res);
        if (tmp != -1)
          minStep = min(minStep, 1 + tmp);
      }
      //结果回填
      dp[target] = (minStep == INT_MAX) ? -1 : minStep;
      return dp[target];
    }
  }
};