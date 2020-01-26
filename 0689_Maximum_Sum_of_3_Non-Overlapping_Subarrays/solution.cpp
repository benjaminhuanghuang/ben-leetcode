/*
689. Maximum Sum of 3 Non-Overlapping Subarrays

https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/
*/

#include <numeric>
#include <vector>
using namespace std;
/*
https://www.cnblogs.com/grandyang/p/8453386.html

*/
class Solution
{
public:
  vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
  {
    int n = nums.size(), mx = INT_MIN;
    vector<int> sums{0}, res, left(n, 0), right(n, n - k);
    for (int num : nums)
      sums.push_back(sums.back() + num);
    for (int i = k, total = sums[k] - sums[0]; i < n; ++i)
    {
      if (sums[i + 1] - sums[i + 1 - k] > total)
      {
        left[i] = i + 1 - k;
        total = sums[i + 1] - sums[i + 1 - k];
      }
      else
      {
        left[i] = left[i - 1];
      }
    }
    for (int i = n - 1 - k, total = sums[n] - sums[n - k]; i >= 0; --i)
    {
      if (sums[i + k] - sums[i] >= total)
      {
        right[i] = i;
        total = sums[i + k] - sums[i];
      }
      else
      {
        right[i] = right[i + 1];
      }
    }
    for (int i = k; i <= n - 2 * k; ++i)
    {
      int l = left[i - 1], r = right[i + k];
      int total = (sums[i + k] - sums[i]) + (sums[l + k] - sums[l]) + (sums[r + k] - sums[r]);
      if (mx < total)
      {
        mx = total;
        res = {l, i, r};
      }
    }
    return res;
  }
};

/*
 https://github.com/YaokaiYang-assaultmaster/LeetCode/blob/master/LeetcodeAlgorithmQuestions/689.%20Maximum%20Sum%20of%203%20Non-Overlapping%20Subarrays.md

  */