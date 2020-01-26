/*
611. Valid Triangle Number

https://leetcode.com/problems/valid-triangle-number/
*/
#include <vector>
using namespace std;
/*
https://zxi.mytechroad.com/blog/math/leetcode-611-valid-triangle-number/
Sort + Two points
a + b > c
a <= b <= c
Time Complexity:
O(n^2)
*/

class Solution
{
public:
  int triangleNumber(vector<int> &nums)
  {
    if (nums.size() < 3)
      return 0;

    // descending
    std::sort(nums.rbegin(), nums.rend());

    int n = nums.size();
    int ans = 0;
    
    // c b........a
    for (int c = 0; c < n - 2; ++c)
    {
      int b = c + 1;
      int a = n - 1;
      while (b < a)
      {
        if (nums[a] + nums[b] > nums[c])
        {
          ans += (a - b);
          ++b;
        }
        else
        {
          --a;
        }
      }
    }

    return ans;
  }
};
