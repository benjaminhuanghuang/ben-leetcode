/*
268. Missing Number
https://leetcode.com/problems/missing-number/s
*/
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return  (0+n)*(n+1)/2 - sum;
    }
};

class Solution_XOR {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for(int i=1;i<=n;++i)
            x = x ^ i ^ nums[i-1];
        return x;
    }
};