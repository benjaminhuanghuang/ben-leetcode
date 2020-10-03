/*
15. 3Sum

https://leetcode.com/problems/3sum/
*/
#include <vector>
#include <algorithm>

/*
https://zxi.mytechroad.com/blog/two-pointers/leetcode-15-3sum/
选取 base number， 然后在剩余的数字里使用双指针，寻找两个数的合等于 -base
注意去除duplicated number

Solution 1: Sorting + Two pointers
Time complexity: O(nlogn + n^2)

Space complexity: O(1)
*/
using namespace std;

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    vector<vector<int>> ans;
    std::sort(nums.begin(), nums.end());
    const int n = nums.size();
    for (int i = 0; i < n - 2; ++i)
    {
      if (nums[i] > 0)   // nums[i] is the base number
        break;
      // skip the duplicated base number  
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      // double points
      int l = i + 1;
      int r = n - 1;
      while (l < r)
      {
        if (nums[i] + nums[l] + nums[r] == 0)
        {
          ans.push_back({nums[i], nums[l++], nums[r--]});
          // skip the duplicated base number !!! 
          while (l < r && nums[l] == nums[l - 1])
            ++l;
          while (l < r && nums[r] == nums[r + 1])
            --r;
        }
        else if (nums[i] + nums[l] + nums[r] < 0)
        {
          ++l;
        }
        else
        {
          --r;
        }
      }
    }
    return ans;
  }
};