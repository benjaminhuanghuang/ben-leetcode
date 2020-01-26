/*
26. Remove Duplicates from Sorted Array

https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/
*/
#include <vector>

using namespace std;
class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    const int len = nums.size();
    if (len <= 1)
      return len;

    int end = 0;
    int i = 1;
    while (i < len)
    {
      if (nums[i] != nums[end])
      {
        nums[++end] = nums[i];
      }
      i++;
    }
    return end + 1;
  }
};