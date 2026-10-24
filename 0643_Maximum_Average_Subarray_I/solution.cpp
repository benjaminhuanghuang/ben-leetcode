#include <vector>

using namespace std;
/*
https://zxi.mytechroad.com/blog/algorithms/array/leetcode-643-maximum-average-subarray-i/

Solution: Sliding Window
*/
class Solution
{
public:
  double findMaxAverage(vector<int> &nums, int k)
  {
    const int n = nums.size();
    int sum = 0;
    int ans = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
      if (i >= k)
        sum -= nums[i - k];
      sum += nums[i];
      if (i + 1 >= k)
        ans = max(ans, sum);
    }
    return static_cast<double>(ans) / k;
  }
};