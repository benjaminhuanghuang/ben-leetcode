/*
179. Largest Number

Level: Medium

https://leetcode.com/problems/largest-number
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
  string largestNumber(vector<int> &nums)
  {
    if (nums.size() == 0)
    {
      return "";
    }
    int n = nums.size();
    vector<string> str_nums(n);
    for (int i = 0; i < n; i++)
    {
      str_nums[i] = to_string(nums[i]);
    }
    sort(str_nums.begin(), str_nums.end(), [](const string &s1, const string &s2) {
      return s1 + s2 > s2 + s1;
    });

    if (str_nums[0][0] == '0')
    {
      return "0";
    }

    string rs;
    for (auto x : str_nums)
    {
      rs += x;
    }
    return rs;
  }
};
