/*
1526. Minimum Number of Increments on Subarrays to Form a Target Array

Level: Hard

https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array
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
  https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1526-minimum-number-of-increments-on-subarrays-to-form-a-target-array/
  
*/

class Solution
{
public:
  int minNumberOperations(vector<int> &target)
  {
    int ans = target[0];
    for (int i = 1; i < target.size(); ++i)
      ans += max(0, target[i] - target[i - 1]);
    return ans;
  }
};