/*
873. Length of Longest Fibonacci Subsequence
https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/
*/
#include <vector>
#include <unordered_set>

using namespace std;

/*
https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-873-length-of-longest-fibonacci-subsequence/
*/
class Solution
{
public:
  int lenLongestFibSubseq(vector<int> &A)
  {
    const int n = A.size();
    unordered_set<int> m(begin(A), end(A));
    int ans = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
      {
        int a = A[i];
        int b = A[j];
        int c = a + b;
        int l = 2;
        while (m.count(c))
        {
          a = b;
          b = c;
          c = a + b;
          ans = max(ans, ++l);
        }
      }
    return ans;
  }
};