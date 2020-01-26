/*
1049. Last Stone Weight II

https://leetcode.com/problems/last-stone-weight-ii/
*/

#include <vector>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

/*
https://zxi.mytechroad.com/blog/leetcode/leetcode-weekly-contest-137/

Solution: DP / target sum
Time complexity: O(n * S) = O(n * 100)
Space complexity: O(S) = O(100)
*/
class Solution
{
public:
  int lastStoneWeightII(vector<int> &stones)
  {
    const int n = stones.size();
    const int max_sum = accumulate(begin(stones), end(stones), 0);
    unordered_set<int> sums;
    sums.insert(stones[0]);
    sums.insert(-stones[0]);
    for (int i = 1; i < n; ++i)
    {
      unordered_set<int> tmp;
      for (int s : sums)
      {
        tmp.insert(s + stones[i]);
        tmp.insert(s - stones[i]);
      }
      swap(tmp, sums);
    }
    int ans = INT_MAX;
    for (int s : sums)
      ans = min(ans, abs(s));
    return ans;
  }
};