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
  int removeDuplicates2(vector<int> &nums)
  {
    const int len = nums.size();
    if (len <= 1)
      return len;

    int i = 0; // 0 ~ i-1 are processed
    int j = 0;
    while (j < len)
    {
      if (i ==0 || nums[i-1] != nums[j])
      {
        nums[i++] = nums[j++];
      }
      else{
        j++;
      }
    }
    // [0, i)
    return i;
  }
};