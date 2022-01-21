/*
154. Find Minimum in Rotated Sorted Array II

https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

与#153 的区别： 有重复的数字
*/
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            if (nums[low] < nums[high])
                return nums[low];
            int mid = (high - low) / 2 + low;

            if (nums[mid] < nums[low]) { 
                high = mid;  //left part should include mid itself.
            } else if (nums[mid] > nums[low]) {
                low = mid + 1;
            } else {
                low++;
            }
        }
        return nums[low];
    }
};