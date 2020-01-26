/*
1040. Moving Stones Until Consecutive II
*/
#include <vector>
#include <string>

using namespace std;

/*
https://zxi.mytechroad.com/blog/leetcode/leetcode-weekly-contest-135-1037-1038-1039-1040/

Solution: Sliding Window

Time complexity: O(nlogn)
Space complexity: O(1)
*/
class Solution {
public:
  vector<int> numMovesStonesII(vector<int>& stones) {
    const int n = static_cast<int>(stones.size());
    sort(begin(stones), end(stones));
    int max_steps = max(stones[n - 1] - stones[1] - n + 2,
                        stones[n - 2] - stones[0] - n + 2);
    int min_steps = INT_MAX;
    int i = 0;
    for (int j = 0; j < n; ++j) {
      while (stones[j] - stones[i] >= n) ++i;
      if (j - i + 1 == n - 1 && stones[j] - stones[i] == n - 2)
        min_steps = min(min_steps, 2);
      else
        min_steps = min(min_steps, n - (j - i + 1));
    }
    return {min_steps, max_steps};
  }
};