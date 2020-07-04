/*
494. Target Sum

Level: Medium

https://leetcode.com/problems/target-sum
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <numeric>
#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;


/*
  Solution: 
  https://www.youtube.com/watch?v=r6Wz4W1TbuI

  https://www.youtube.com/watch?v=zks6mN06xdQ

*/

/*

  DFS

  Time complexity: O(2^n)

  Space complexity: O(n)

*/
class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int S) {
    const int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum < std::abs(S)) return 0;
    int ans = 0;
    dfs(nums, 0, S, ans);
    return ans;
  }
private:
  void dfs(const vector<int>& nums, int d, int S, int& ans) {
    if (d == nums.size()) {
      if (S == 0) ++ans;
      return;
    }    
    dfs(nums, d + 1, S - nums[d], ans);
    dfs(nums, d + 1, S + nums[d], ans);
  }
};

/*
  DP

  Time complexity: O(n*sum)

  Space complexity: O(n*sum)
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
      const int n = nums.size();
      const int sum = std::accumulate(nums.begin(), nums.end(), 0);
      if (sum < S) return 0;
      const int offset = sum;
      // ways[i][j] means total ways to sum up to (j - offset) using nums[0] ~ nums[i - 1].
      vector<vector<int>> ways(n + 1, vector<int>(sum + offset + 1, 0));
      ways[0][offset] = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = nums[i]; j < 2 * sum + 1 - nums[i]; ++j)
          if (ways[i][j]) {
            ways[i + 1][j + nums[i]] += ways[i][j];
            ways[i + 1][j - nums[i]] += ways[i][j];
          }        
      }
      
      return ways.back()[S + offset];
    }
};