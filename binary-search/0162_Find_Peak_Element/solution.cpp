/*
162. Find Peak Element
https://leetcode.com/problems/find-peak-element/

*/
#include <vector>

using namespace std;

class Solution
{
public:
  int findPeakElement(vector<int> &nums)
  {
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      // 如果[mid-1]>[mid]，那么peak肯定在[low]和[mid-1]之间（闭区间）
      if (mid - 1 >= 0 && nums[mid] < nums[mid - 1])
        high = mid - 1;
      // 如果mid+1大，那么peak肯定在mid+1和hi之间（闭区间）
      else if (mid + 1 < nums.size() && nums[mid] < nums[mid + 1])
        low = mid + 1;
      // 其他情况（peak在开头或者结尾，或者中间）
      else
        return mid;
    }
    return -1;
  }
};