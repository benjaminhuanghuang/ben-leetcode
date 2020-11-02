/*
442. Find All Duplicates in an Array

https://leetcode.com/problems/find-all-duplicates-in-an-array/
*/
#include <vector>
#include <cmath>

using namespace std;
/*
对于每个nums[i]，将其对应的nums[nums[i] - 1]取相反数，如果其已经是负数了，说明之前存在过，我们将其加入结果res中
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) 
              res.push_back(idx + 1);
            nums[idx] = -nums[idx];
        }
        return res;
    }
};