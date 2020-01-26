/*
724. Find Pivot Index
https://leetcode.com/problems/find-pivot-index/
*/
#include <vector>
#include <numeric>

using namespace std;
class Solution_Error
{
public:
  int pivotIndex(vector<int> &nums)
  {
    if (nums.empty())
      return -1;

    int l = 0;
    int r = nums.size() - 1;
    int sumL = 0, sumR = 0;
    while (l < r)
    {
      if (sumL < sumR)
        sumL += nums[l++];
      else
        sumR += nums[r--];
    }
    if (sumL == sumR)
      return l;
    else
      return -1;
  }
};

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        int l = 0;
        int r = sum;
        for (int i = 0; i < nums.size(); ++i) {
            r -= nums[i];
            if (l == r) return i;
            l += nums[i];
        }
        return -1;
    }
};