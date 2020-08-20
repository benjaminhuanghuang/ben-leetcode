/*
312. Burst Balloons

Level: Hard

https://leetcode.com/problems/burst-balloons
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
  Solution: DP
  http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-312-burst-balloons/
*/

class Solution
{
public:
  int maxCoins(vector<int> &nums)
  {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    // c[i][j] = maxCoins(nums[i:j+1])
    vector<vector<int>> c(n + 2, vector<int>(n + 2, 0));

    for (int l = 1; l <= n; ++l)
      for (int i = 1; i <= n - l + 1; ++i)
      {
        int j = i + l - 1;
        for (int k = i; k <= j; ++k)
        {
          c[i][j] = max(c[i][j], c[i][k - 1] + nums[i - 1] * nums[k] * nums[j + 1] + c[k + 1][j]);
        }
      }

    return c[1][n];
  }
};

/*
  Recursion with memoization 
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        // c[i][j] = maxCoins(nums[i:j+1])
        c_ = vector<vector<int>>(n+2, vector<int>(n+2, 0));
        
        return maxCoins(nums, 1, n);
    }
private:
    int maxCoins(const vector<int>& nums, const int i, const int j) {
        if(i>j) return 0;
        if(c_[i][j]>0) return c_[i][j];
        
        if(i==j) return nums[i-1]*nums[i]*nums[i+1];
        
        int ans=0;
        for(int k=i;k<=j;++k)
             ans=max(ans, maxCoins(nums,i,k-1) + nums[i-1]*nums[k]*nums[j+1] + maxCoins(nums, k+1, j));
        
        c_[i][j] = ans;
        
        return c_[i][j];
    }
    
    vector<vector<int>> c_;
};

