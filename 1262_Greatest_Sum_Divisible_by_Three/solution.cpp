/*
1262. Greatest Sum Divisible by Three

Level: Medium

https://leetcode.com/problems/greatest-sum-divisible-by-three
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
  https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1262-greatest-sum-divisible-by-three/
*/

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
       vector<int> dp(3);    
    for (int num : nums) {
      vector<int> tmp(dp);
      for (int s : tmp)
        dp[(s + num) % 3] = max(dp[(s + num) % 3], s + num);      
    }
    return dp[0];  
    }
};