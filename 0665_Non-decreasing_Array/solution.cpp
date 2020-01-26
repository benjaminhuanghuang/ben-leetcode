/*
665. Non-decreasing Array

https://leetcode.com/problems/non-decreasing-array/
*/
#include <vector>

using namespace std;


class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool found = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                if (found) return false;
                else {
                    if (i - 2 >= 0 && nums[i] < nums[i - 2])
                        nums[i] = nums[i - 1];
                    found = true;
                }
            }
        }
        return true;
    }
};