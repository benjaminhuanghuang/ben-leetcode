/*
907. Sum of Subarray Minimums

https://leetcode.com/problems/sum-of-subarray-minimums/
*/
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
  int sumSubarrayMins(vector<int> &A)
  {
    constexpr int kMod = 1e9 + 7;
    int ans = 0;
    for (int i = 0; i < A.size(); ++i)
    {
      int left = 0;
      for (int j = i - 1; j >= 0 && A[j] > A[i]; --j, ++left)
        ;
      int right = 0;
      for (int j = i + 1; j < A.size() && A[j] >= A[i]; ++j, ++right)
        ;
      ans = (ans + static_cast<long>(A[i]) * (left + 1) * (right + 1)) % kMod;
    }
    return ans;
  }
};
/*
https://zxi.mytechroad.com/blog/stack/leetcode-907-sum-of-subarray-minimums/
Monotonic Stack
Time complexity: O(n)

Space complexity: O(n)
*/
class Solution
{
public:
  int sumSubarrayMins(vector<int> &A)
  {
    constexpr int kMod = 1e9 + 7;
    const int n = A.size();
    vector<int> left(n);
    vector<int> right(n);
    stack<pair<int, int>> s;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
      int len = 1;
      while (!s.empty() && s.top().first > A[i])
      {
        len += s.top().second;
        s.pop();
      }
      s.emplace(A[i], len);
      left[i] = len;
    }
    while (!s.empty())
      s.pop();
    for (int i = n - 1; i >= 0; --i)
    {
      int len = 1;
      while (!s.empty() && s.top().first >= A[i])
      {
        len += s.top().second;
        s.pop();
      }
      s.emplace(A[i], len);
      right[i] = len;
    }
    for (int i = 0; i < n; ++i)
      ans = (ans + static_cast<long>(left[i]) * A[i] * right[i]) % kMod;
    return ans;
  }
};