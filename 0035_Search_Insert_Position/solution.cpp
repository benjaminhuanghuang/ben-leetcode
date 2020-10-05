/*
35. Search Insert Position

https://leetcode.com/problems/search-insert-position/
*/

#include <vector>

using namespace std;


/*
 Template by HuaHua
*/
class Solution
{
public:
  int searchInsert(vector<int> &nums, int target)
  {
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r)
    {
      int mid = l + (r - l) / 2;
      if (nums[mid] > target)
      {
        r = mid - 1;
      }
      else if (nums[mid] < target)
      {
        l = mid + 1;
      }
      else
      {
        return mid;
      }
    }
    return l;
  }
};



class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       
        int l = 0;
        int r = nums.size();
        
        while(l < r){
            int mid = l + ((r - l) >> 1);
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                l = mid + 1;
            }
            else // nums[mid] > target
            {
                r = mid;
            }          
        }
        return l;
    }
};