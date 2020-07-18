/*
264. Ugly Number II

Level: Medium

https://leetcode.com/problems/ugly-number-ii
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
  http://zxi.mytechroad.com/blog/math/leetcode-264-ugly-number-ii/

*/

class Solution
{
public:
  int nthUglyNumber(int n)
  {
    vector<int> nums;
    for (long a = 1; a <= INT_MAX; a *= 2)
      for (long b = a; b <= INT_MAX; b *= 3)
        for (long c = b; c <= INT_MAX; c *= 5)
          nums.push_back(c);
    std::sort(nums.begin(), nums.end());
    return nums[n - 1];
  }
};

/*
  new_num = min(ugly_num[i2] * 2, ugly_num[i3]*3, ugly_num[i5]*5)

  Time O(N)
  Space O(N)
*/
class Solution_2
{
public:
  int nthUglyNumber(int n)
  {
    static vector<int> nums{1};
    static int i2 = 0;
    static int i3 = 0;
    static int i5 = 0;
    while (nums.size() < n)
    {
      const int next2 = nums[i2] * 2;
      const int next3 = nums[i3] * 3;
      const int next5 = nums[i5] * 5;
      const int next = min(next2, min(next3, next5));
      if (next == next2)
        ++i2;
      if (next == next3)
        ++i3;
      if (next == next5)
        ++i5;
      nums.push_back(next);
    }
    return nums[n - 1];
  }
};