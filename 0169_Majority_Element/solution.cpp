/*
169. Majority Element

https://leetcode.com/problems/majority-element/
*/
#include <vector>

using namespace std;


/*
O(nlogn) 
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
/*
  O(N)
*/
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums.front();
        int count = 0;
        
        for (const int num : nums) {
            if (num == majority) ++count;
            else if (--count == 0) {
                count = 1;
                majority = num;
            }
        }
        
        return majority;
    }
};