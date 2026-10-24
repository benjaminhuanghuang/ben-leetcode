/*
11. Container With Most Water

https://leetcode.com/problems/container-with-most-water/
*/
#include <vector>

using namespace std;

/*
http://zxi.mytechroad.com/blog/two-pointers/leetcode-11-container-with-most-water/

Solution: two pointers
Time complexity: O(n)
Space complexity: O(1)

Brute force:  O(N^2)
*/

class Solution
{
public:
  int maxArea(vector<int> &height)
  {
    int ans = 0;
    int l = 0;
    int r = height.size() - 1;
    while (l < r)
    {
      int h = min(height[l], height[r]);
      ans = max(ans, h * (r - l));
      if (height[l] < height[r]) // 每次舍弃比较低的
        ++l;
      else
        --r;
    }
    return ans;
  }
};