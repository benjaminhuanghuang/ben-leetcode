/*
842. Split Array into Fibonacci Sequence

https://leetcode.com/problems/split-array-into-fibonacci-sequence/
*/

#include <vector>
#include <string>

using namespace std;
/*
https://zxi.mytechroad.com/blog/searching/leetcode-842-split-array-into-fibonacci-sequence/
*/
class Solution
{
public:
  vector<int> splitIntoFibonacci(string S)
  {
    vector<int> nums;
    dfs(S, 0, nums);
    return nums;
  }

private:
  bool dfs(const string &s, int start, vector<int> &nums)
  {
    if (start == s.length())
      return nums.size() > 2;
    size_t max_len = s[start] == '0' ? 1 : 10;
    long num = 0;
    for (int i = start; i < min(start + max_len, s.length()); ++i)
    {
      num = num * 10 + (s[i] - '0');
      if (num > INT_MAX)
        break;
      if (nums.size() >= 2)
      {
        long sum = static_cast<long>(nums.rbegin()[0]) + nums.rbegin()[1];
        if (sum < num)
          break;
        if (sum > num)
          continue;
      }
      nums.push_back(num);
      if (dfs(s, i + 1, nums))
        return true;
      nums.pop_back();
    }
    return false;
  }
};