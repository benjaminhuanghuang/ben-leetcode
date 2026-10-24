/*
55. Jump Game II

https://leetcode.com/problems/jump-game/

[#45]
*/
#include <vector>

using namespace std;
/*
https://www.youtube.com/watch?v=r3pZd9ghqxk
            2, 3, 1, 4, 2, 1, 1
maxReach    2  4   

Time complexity: O(n)
Space complexity: O(1)
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()  <2)
          return true;
        
        int reach = 0;
        for (int i = 0; i <= reach && i < nums.size(); i++) {
            if (i >= nums.size() - 1)
                return true;
            reach = max(reach, nums[i] + i);
        }

        return false;
    }
};

class Solution2 {
public:
    bool canJump(vector<int>& nums) {
         int index = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] + i >= index) {
                index = i;
            }
        }

        return index <= 0;
    }
};