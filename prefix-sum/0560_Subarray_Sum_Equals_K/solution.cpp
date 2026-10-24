/*
560. Subarray Sum Equals K

https://leetcode.com/problems/subarray-sum-equals-k/
*/
#include <vector>
#include <unordered_map>

using namespace std;
/*
https://zxi.mytechroad.com/blog/hashtable/leetcode-560-subarray-sum-equals-k/

Solution 0: Brute Force + Prefix sun

Precompute the prefix sum and check sum of nums[i:j] in O(1)

Time complexity: O(n^2)
Space complexity: O(n)
*/
class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    const int n = nums.size();
    vector<int> sums(n + 1, 0);    
    for (int i = 1; i <= n; ++i)
      sums[i] = sums[i - 1] + nums[i - 1];
    int ans = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i; j < n; ++j)
        if (sums[j + 1] - sums[i] == k) ++ans;
    return ans;
  }
};
/*
Solution 1: Running Prefix sum
prefixSum array : 用于解决和 sum of subarray 相关问题
    prefixSum[x] = sum of subArray(0, x)
                 = prefixSum[x - 1] + nums[x]
    sum of subarray(i,j) = prefixSum[j] - prefixSum[i-1]


Time complexity: O(n)
Space complexity: O(n)
*/
class Solution
{
public:
  int subarraySum(vector<int> &nums, int k)
  {
    if (nums.empty())
      return 0;
    //// 记录prefixSum出现的value和个数
    unordered_map<int, int> counts{{0, 1}};
    int cur_sum = 0;
    int ans = 0;
    for (const int num : nums)
    {
      cur_sum += num;
      ans += counts[cur_sum - k];
      ++counts[cur_sum];
    }
    return ans;
  }
};