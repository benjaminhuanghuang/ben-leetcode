/*
153. Find Minimum in Rotated Sorted Array

https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
*/

#include <vector>

using namespace std;

 /*
  if the mid is greater than low and high, mid is in front of pivot, search from mid to high;
  otherwise, search from low to mid; 
  
  Special case is the array is sorted(1, 2, 3, 4,…), and
  mid point to the first element of the array(1), so recursively find left part should include
  mid itself.
 */
class Solution
{
public:
  int findMin(vector<int> &nums)
  {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
      if (low == high)
        return nums[low];
      int mid = (high - low) / 2 + low;
      if (nums[mid] > nums[high]) // mid located in left part (bigger part)
      {
        //search from mid to high
        low = mid + 1;
      }
      else
      { //search from low to mid
        high = mid;  //left part should include mid itself.
      }
    }
    return INT_MAX;
  }
};
/*
https://zxi.mytechroad.com/blog/leetcode/leetcode-153-find-minimum-in-rotated-sorted-array/
Time complexity:

T(n) = O(1) + T(n/2) = O(logn)
*/
class Solution2 {
public:
    int findMin(vector<int> &num) {
        return findMin(num, 0, num.size()-1);
    }
    
private:
    int findMin(const vector<int>& num, int l, int r)
    {
        // Only 1 or 2 elements
        if (l+1 >= r) return min(num[l], num[r]);
        
        // Sorted
        if (num[l] < num[r]) return num[l];
        
        int mid = l + (r-l)/2; 
        
        return min(findMin(num, l, mid-1), 
                   findMin(num, mid, r));
    }
};