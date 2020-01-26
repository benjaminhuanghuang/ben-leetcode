/*
891. Sum of Subsequence Widths
https://leetcode.com/problems/sum-of-subsequence-widths/
*/
#include <vector>
using namespace std;


/*
https://zxi.mytechroad.com/blog/math/leetcode-891-sum-of-subsequence-widths/
*/
class Solution
{
public:
  int sumSubseqWidths(vector<int> &A)
  {
    constexpr long kMod = 1e9 + 7;
    const int n = A.size();
    sort(begin(A), end(A));
    long ans = 0;
    long p = 1;
    for (int i = 0; i < n; ++i)
    {
      ans = (ans + (A[i] - A[n - i - 1]) * p) % kMod;
      p = (p << 1) % kMod;
    }
    return (ans + kMod) % kMod;
  }
};