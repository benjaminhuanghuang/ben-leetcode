/*
503. Next Greater Element II

Level: Medium

https://leetcode.com/problems/next-greater-element-ii
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
  https://www.youtube.com/watch?v=5IAq5jd8O7Y
*/

/*
  Time O(n^2)
*/
class Solution_Naive
{
public:
  vector<int> nextGreaterElements(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> res(n);

    for (int i = 0; i < nums.size(); i++)
    {
      res[i] = -1;
      for (int j = 1; j < nums.size(); j++) //j 是 i 之后的第j个元素
      {
        if (nums[(i + j) % nums.size()] > nums[i])
        {
          res[i] = nums[(i + j) % nums.size()];
          break;
        }
      }
    }
    return res;
  }
};

/*
  Use Monotonic Stacks maintain the index.
  Time O(n) Space O(n)
*/
class Solution_MonoStack
{
public:
  vector<int> nextGreaterElements(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> res(n);

    stack<int> s;

    // 处理 circular array 的技巧  假设array 重复
    for (int i = 2 * nums.size() - 1; i >= 0; i--)
    {
      // 
      while (!s.empty() && nums[s.top()] <= nums[i % nums.size()])
      {
        // 直到当前元素比stack 顶部元素小或stack is empty
        s.pop();
      }

      res[i % nums.size()] = s.empty() ? -1 : nums[s.top()];
      s.push(i % nums.size());
    }
    return res;
  }
};