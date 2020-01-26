/*
945. Minimum Increment to Make Array Unique
https://leetcode.com/problems/minimum-increment-to-make-array-unique/
*/
#include <vector>
#include <string>

using namespace std;
/*
https://zxi.mytechroad.com/blog/greedy/leetcode-945-minimum-increment-to-make-array-unique/
Sort the elements, make sure A[i] >= A[i-1] + 1, if not increase A[i] to A[i – 1] + 1

Time complexity: O(nlogn)

Space complexity: O(1)
*/
class Solution
{
public:
  int minIncrementForUnique(vector<int> &A)
  {
    int ans = 0;
    sort(begin(A), end(A));
    for (int i = 1; i < A.size(); ++i)
    {
      if (A[i] > A[i - 1])
        continue;
      ans += (A[i - 1] - A[i]) + 1;
      A[i] = A[i - 1] + 1;
    }
    return ans;
  }
};