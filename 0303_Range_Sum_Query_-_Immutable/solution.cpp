/*
303. Range Sum Query - Immutable

Level: Easy

https://leetcode.com/problems/range-sum-query-immutable
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-303-range-sum-query-immutable/
*/

class NumArray
{
public:
  NumArray(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 0)
    {
      return;
    }
    sums = vector<int>(n,0);
    sums[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
      sums[i] = sums[i - 1] + nums[i];
    }
  }

  int sumRange(int i, int j)
  {
    if (i == 0)
      return sums[j];
    return sums[j] - sums[i - 1];
  }

private:
  vector<int> sums; // sums[i] = nums[0] + nums[1]... nums[i]
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */