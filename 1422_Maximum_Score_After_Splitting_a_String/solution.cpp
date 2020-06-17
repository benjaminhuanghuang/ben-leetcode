/*
1422. Maximum Score After Splitting a String

Level: Easy

https://leetcode.com/problems/maximum-score-after-splitting-a-string
*/
#include <vector>
#include <string>
#include <unordered_set>

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
  int maxScore(string s)
  {
    int count_1 = std::count_if(s.begin(), s.end(), [](char c) { return c == '1'; });
    int res = 0;
    int count_1_left = 0;
    int count_0_left = 0;
    for (auto it = s.begin(); it != s.end(); ++it)
    {
      if (*it == '0')
        count_0_left += 1;
      else
        count_1_left += 1;

      res = max(res, count_0_left + (count_1 - count_1_left));
    }
    return res;
  }
};