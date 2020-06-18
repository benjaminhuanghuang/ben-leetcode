/*
1403. Minimum Subsequence in Non-Increasing Order

Level: Easy

https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order
*/
#include <vector>
#include <string>
#include <unordered_set>

#include <algorithm>
#include <numeric>  //accumulate
#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;


/*
  Solution: 
  把数字分成两分，一份比另一份大
*/

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ans;
        std::sort(nums.rbegin(), nums.rend());
        int currentSum= 0;
        for(int n : nums){
          currentSum +=n;
          ans.push_back(n);
          if(currentSum > sum - currentSum)
          {
            break;
          }
        }

        return ans;
    }
};