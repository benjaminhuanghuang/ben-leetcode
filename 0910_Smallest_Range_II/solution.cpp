/*
910. Smallest Range II

Level: Medium

https://leetcode.com/problems/smallest-range-ii
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  https://zxi.mytechroad.com/blog/greedy/leetcode-910-smallest-range-ii/
  Sort the array and compare adjacent numbers.
*/

class Solution
{
public:
  int smallestRangeII(vector<int> &A, int K)
  {
    sort(begin(A), end(A));
    int ans = A.back() - A.front();
    for (int i = 1; i < A.size(); ++i)
    {
      int l = min(A.front() + K, A[i] - K);
      int h = max(A.back() - K, A[i - 1] + K);
      ans = min(ans, h - l);
    }
    return ans;
  }
};