/*
16. 3Sum Closest

https://leetcode.com/problems/3sum-closest/
*/
#include <vector>

using namespace std;

/*
Solution: Sorting + Two Pointers
Similar to #15. 3Sum
Time complexity: O(n^2)
Space complexity: O(1)
*/
class Solution
{
public:
  int threeSumClosest(vector<int> &num, int target)
  {
    int n = num.size();
    int minDiff = INT_MAX;
    int ans = target;
    sort(num.begin(), num.end());

    for (int i = 0; i < n - 2; i++)
    {
      int l = i + 1, r = n - 1;
      while (l < r)
      {
        int sum = num[i] + num[l] + num[r];
        if (sum == target)
          return target;

        int diff = abs(sum - target);
        if (diff < minDiff)
        {
          minDiff = diff;
          ans = sum;
        }

        if (sum > target)
          --r;
        else
          ++l;
      }
    }

    return ans;
  }
};