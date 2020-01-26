/*
485. Max Consecutive Ones
https://leetcode.com/problems/max-consecutive-ones/
*/
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.empty())
          return 0;
        int ans = 0;
        int count =0;
        for (auto num : nums){
          if(num == 0)
          {
            ans = max(ans, count);
            count =0;
          }
          else
          {
           count++; 
          }
        }
        return max(ans, count);
    }
};