/*
53. Maximum Subarray

https://leetcode.com/problems/maximum-subarray/
*/

#include <vector>

using namespace std;
/*
    从头遍历这个数组。对于数组中的其中一个元素，它只有两个选择：

     1. 要么加入之前的数组加和之中（跟别人一组）

     2. 要么自己单立一个数组（自己单开一组）

     所以对于这个元素应该如何选择，就看他能对哪个组的贡献大。如果跟别人一组，能让总加和变大，还是跟别人一组好了；
     如果自己起个头一组，自己的值比之前加和的值还要大，那么还是自己单开一组好了。

    所以利用一个sum数组，记录每一轮sum的最大值，sum[i]表示当前这个元素是跟之前数组加和一组还是自己单立一组好，

     */
class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    vector<int> sum(nums.size());
    int ans = nums[0];
    sum[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
      sum[i] = max(nums[i], sum[i - 1] + nums[i]);
      ans = max(ans, sum[i]);
    }
    return ans;
  }
};