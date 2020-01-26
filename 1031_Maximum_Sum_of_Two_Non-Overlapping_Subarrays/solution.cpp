// https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/

#include <vector>
#include <climits>

using namespace std;

/*
  Sliding window and prefix sum 
  Time complexity  O(N^2)
*/
class Solution
{
public:
  int maxSumTwoNoOverlap(vector<int> &A, int L, int M)
  {
    const int n = A.size();

    vector<int> prefixSum(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
      prefixSum[i + 1] = prefixSum[i] + A[i];
    }

    int ans = 0;
    for (int i = 0; i <= n - L; ++i)
    {
      int ls = prefixSum[i + L] - prefixSum[i];
      int ms = max(maxSum(prefixSum, 0, i - M - 1, M), maxSum(prefixSum, i + L, n - M, M));
      ans = max(ans, ls + ms);
    }
    return ans;
  }

private:
  int maxSum(const vector<int> &prefixSum, int start, int end, int l)
  {
    int ans = INT_MIN;
    for (int i = start; i <= end; i++)
    {
      ans = max(ans, prefixSum[i + l] - prefixSum[i]);
    }
    return ans;
  }
};