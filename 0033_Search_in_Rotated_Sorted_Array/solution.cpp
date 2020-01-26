/*
33. Search in Rotated Sorted Array

https://leetcode.com/problems/search-in-rotated-sorted-array/
*/

#include <vector>

using namespace std;

/*
  Use tempalte by HuaHua
  https://www.youtube.com/watch?v=lWEIIFFflQY

  注意所有的区间都是闭区间
*/
class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    if (nums.size() == 0)
      return -1;

    int l = 0;
    int r = nums.size() - 1;

    while (l <= r)
    {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target)
      {
        return mid;
      }
      else if (nums[l] <= nums[mid]) // mid located in left part, which is increasing
      {
        if (nums[l] <= target && target < nums[mid]) //  target located between left and mid
          r = mid - 1;
        else //  target is bigger than mid
          l = mid + 1;
      }
      else // nums[l] > nums[mid] , mid located in right part, which is increasing
      {
        if (nums[mid] < target && target <= nums[r]) //target located between mid and right
          l = mid + 1;
        else // target is less than mid
          r = mid - 1;
      }
    }
    return -1;
  }
};