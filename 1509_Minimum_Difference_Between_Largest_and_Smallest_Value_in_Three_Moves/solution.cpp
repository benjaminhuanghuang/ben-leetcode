/*
1509. Minimum Difference Between Largest and Smallest Value in Three Moves

Level: Medium

https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves
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
  如果数字的个数小于等于 4 个，则答案为 0。
  将数组从小到大排序。直觉上看，我们会修改最大的若干个数字或者最小的若干个数字。
  有四种选择，修改最小的三个数字，修改最小的两个数字和最大的数字，修改最小的数字和最大的两个数字，以及修改最大的三个数字。
*/

class Solution
{
public:
  int minDifference(vector<int> &nums)
  {
    if (nums.size() <= 3)
      return 0;

    sort(nums.begin(), nums.end());

    int n = nums.size();

    // [0, 1, 2, 3 ..... n-4, n-3, n-2, n-1]
    return min(min(nums[n - 1] - nums[3], nums[n - 2] - nums[2]),
               min(nums[n - 3] - nums[1], nums[n - 4] - nums[0]));
  }
};

/*
  Solution: 
  如果数字的个数小于等于 3 个，则答案为 0。（其实 4 个数字也是 0）。
  题目虽然指出可以修改三次，如果允许修改k次呢？
  每次修改开头的 n个数字，和结尾的 k - n 个数字, minDiff = nums[n-1-k+i] - nums[i]
*/

class Solution
{
public:
  int minDifference(vector<int> &nums)
  {
    if (nums.size() <= 4)
      return 0;

    sort(nums.begin(), nums.end());

    int n = nums.size();
    int k = 3;

    // [0, 1, 2, 3 ..... n-4, n-3, n-2, n-1]
    int minDiff = INT_MAX;
    int end = n - 1 - k;
    // i is the nubmer changed at the head
    // n - 1 - k + i is the index of number not changed
    for (int i = 0; i <= k; ++i)
    {
      minDiff = min(minDiff, nums[n - 1 - k + i] - nums[i]);
    }

    return minDiff;
  }
};